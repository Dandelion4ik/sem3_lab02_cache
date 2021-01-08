// Copyright 2020 Your Name <your_email>

#include <experiment.h>
#include <gtest/gtest.h>
#include <source.h>

TEST(Example, EmptyTest) {
    testing_exp exp(std::vector<size_t>{49152, 262144});
    exp.conducting_experiments();
    EXPECT_TRUE(true);
}
