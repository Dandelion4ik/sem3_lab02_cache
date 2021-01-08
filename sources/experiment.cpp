// Copyright 2020 Kavykin Andrey Kaviandr@yandex.ru

#include "experiment.h"
const size_t arg=16;

experiment::experiment(size_t size) { cache_size = size; }

void experiment::initialization() {
  std::random_device rd;
  arr = new int[cache_size];
  for (size_t i = 0; i < cache_size; ++i) {
    arr[i] = (int)rd() % 10000;
  }
}

void experiment::heating() {
  for (size_t i = 0; i < cache_size; i += arg) {
    ++arr[i];
  }
}

void experiment::straight_exp() {
  const int iterations = 1000;
  auto start = std::chrono::system_clock::now();
  for (auto k = 0; k < iterations; ++k) {
    for (size_t i = 0; i < cache_size; i += arg) {
      ++arr[i];
    }
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> straight_time = end - start;
  res["straight"] = straight_time;
}

void experiment::reverse_exp() {
  const int iterations = 1000;
  auto start = std::chrono::system_clock::now();
  for (auto k = 0; k < iterations; ++k) {
    for (size_t i = cache_size; i > 0; i -= arg) {
      ++arr[i];
    }
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> reverse_time = end - start;
  res["reverse"] = reverse_time;
}

void experiment::random_exp() {
  std::random_device rd;
  const int iterations = 1000;
  auto start = std::chrono::system_clock::now();
  for (size_t k = 0; k < iterations; ++k) {
    for (size_t i = 0; i < cache_size; i += arg) {
      ++arr[(rd() % (cache_size / arg)) * arg];
    }
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> random_time = end - start;
  res["random"] = random_time;
}

[[nodiscard]] std::chrono::duration<double> experiment::get_res(
    const std::string& i) const {
  return this->res.at(i);
}
