// Copyright 2020 Kavykin Andrey Kaviandr@yandex.ru

#ifndef CACHE_EXPERIMENT_H
#define CACHE_EXPERIMENT_H

#include <chrono>
#include <iostream>
#include <map>
#include <random>

class experiment {
  size_t cache_size = 0;
  int* arr{};
  std::map<std::string, std::chrono::duration<double>> res = {
      {"straight", {}}, {"reverse", {}}, {"random", {}}};

 public:
  explicit experiment(size_t size);

  void initialization();

  void heating();

  void straight_exp();

  void reverse_exp();

  void random_exp();

  [[nodiscard]] std::chrono::duration<double> get_res(
      const std::string& i) const;
};

#endif  // CACHE_EXPERIMENT_H
