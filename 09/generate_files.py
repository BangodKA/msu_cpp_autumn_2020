from random import randint

for filename in ['test_1.txt', 'test_2.txt', 'test_3.txt']:
  with open('Tests/' + filename[:6] + '/' + filename, 'w') as file:
    for i in range(2 * (int(filename[-5]) - 1) * (100 ** int(filename[-5]))):
      file.write(str(randint(0, 2 ** 64)))
      if i != 2 * (int(filename[-5]) - 1) * (100 ** int(filename[-5])) - 1:
        file.write('\n')