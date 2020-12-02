#include <tuple>

auto ThreadPool::WaitTask() {
  while(true) {
    std::unique_lock<std::mutex> lock(task_taking);
    condition.wait(lock, [this](){return finished_working || !tasks.empty();});
    if (finished_working && tasks.empty()) {
      return;
    }
    auto res = std::move(tasks.front());
    tasks.pop();

    res();
  }
}

ThreadPool::ThreadPool(size_t poolSize) {
  finished_working = false;
  for(size_t i = 0; i < poolSize; ++i) {
    threads.emplace_back([this]() {WaitTask();});
  }
}

template <class Func, class... Args>
auto ThreadPool::exec(Func func, Args... args) -> std::future<decltype(func(args...))> {
  auto task = std::make_shared< std::packaged_task<decltype(func(args...))()> >(
    std::bind(std::forward<Func>(func), std::forward<Args>(args)...)
  );
      
  std::future<decltype(func(args...))> res = task->get_future();
  {
      std::unique_lock<std::mutex> lock(task_taking);
      tasks.emplace([task](){ (*task)(); });
  }
  condition.notify_one();
  return res;
}

ThreadPool::~ThreadPool() {
  {
    std::unique_lock<std::mutex> lock(task_taking);
    finished_working = true;
  }
  condition.notify_all();
  for(std::thread &thread : threads) {
    thread.join();
  }
}