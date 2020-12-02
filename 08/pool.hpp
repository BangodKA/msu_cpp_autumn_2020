#pragma once

#include <condition_variable>
#include <functional>
#include <future>
#include <mutex>
#include <queue>
#include <vector>

class ThreadPool {
 public:
  explicit ThreadPool(size_t poolSize);

  template <class Func, class... Args>
  auto exec(Func func, Args... args) -> std::future<decltype(func(args...))>;

  ~ThreadPool();
 private:
  auto WaitTask();

  std::vector <std::thread> threads;
  std::queue <std::function<void()> > tasks;
  std::mutex task_taking;
  std::condition_variable condition;
  bool finished_working;
};

#include "pool.tpp"