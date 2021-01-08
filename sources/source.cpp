// Copyright 2020 Kavykin Andrey Kaviandr@yandex.ru

#include "source.h"

testing_exp::testing_exp(const std::vector<size_t>& x) { levels_cache = x; }

void testing_exp::print(const std::vector<experiment>& statistics,
                        const std::vector<size_t>& exp_buf) {
    int size_vec = int(statistics.size());
    std::vector<std::string> exp = {"straight", "reverse", "random"};
    for (auto i = 0; i < 3; ++i) {
        std::cout << "investigation: " << std::endl;
        std::cout << "  travel_variant: " << exp[i] << std::endl;
        std::cout << "  experiments: " << std::endl;
        for (auto k = 0; k < size_vec; ++k) {
            std::cout << "  - experiment: " << std::endl;
            std::cout << "      number: " << k + 1 << std::endl;
            std::cout << "      input_data: " << std::endl;
            std::cout << "        buffer_size: " << exp_buf[k] << " byte"
                      << std::endl;
            std::cout << "      results: " << std::endl;
            std::cout << "        duration: " << statistics[k].get_res(exp[i]).count()
                      << std::endl;
        }
    }
}

void testing_exp::conducting_experiments() {
    int size_vec = int(levels_cache.size());
    std::vector<experiment> statistics = {};
    std::vector<size_t> exp_buf = {};
    size_t size_0 = levels_cache[0] * 0.5;
    exp_buf.push_back(size_0);
    experiment bites_0(size_0);
    bites_0.initialization();
    bites_0.heating();
    bites_0.straight_exp();
    bites_0.heating();
    bites_0.reverse_exp();
    bites_0.heating();
    bites_0.random_exp();
    statistics.push_back(bites_0);
    for (auto i = 0; i < size_vec; ++i) {
        size_t size_i = levels_cache[i];
        exp_buf.push_back(size_i);
        experiment bites_i(size_i);
        bites_i.initialization();
        bites_i.heating();
        bites_i.straight_exp();
        bites_i.heating();
        bites_i.reverse_exp();
        bites_i.heating();
        bites_i.random_exp();
        statistics.push_back(bites_i);
    }
    size_t size_last = levels_cache[size_vec - 1] * 1.5;
    experiment bites_last(size_last);
    exp_buf.push_back(size_last);
    bites_last.initialization();
    bites_last.heating();
    bites_last.straight_exp();
    bites_last.heating();
    bites_last.reverse_exp();
    bites_last.heating();
    bites_last.random_exp();
    statistics.push_back(bites_last);
    print(statistics, exp_buf);
}
