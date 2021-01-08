// Copyright 2020 Kavykin Andrey Kaviandr@yandex.ru

#ifndef TEMPLATE_SOURCE_H
#define TEMPLATE_SOURCE_H

#include "experiment.h"

class testing_exp {
 public:
  std::vector<size_t> levels_cache = {};
  explicit testing_exp(const std::vector<size_t>& levels_cache);
  static void print(const std::vector<experiment>& statistics,
                    const std::vector<size_t>& exp_buf);
  void conducting_experiments();
};

#endif  // TEMPLATE_SOURCE_H
