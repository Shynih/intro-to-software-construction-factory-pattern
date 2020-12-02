#ifndef PARSE_TEST_HPP
#define PARSE_TEST_HPP

#include "gtest/gtest.h"

#include "base.cpp"

TEST(ParseTEST, ParseInvalid) {
    int argc = 4;
    char* argv[] = {"calculator", "2", "a", "3"};
    Base* test;
    EXPECT_EQ(test -> parse(argv, argc), nullptr);
}

TEST(ParseTEST, ParseTwo) {
    int argc = 4;
    char* argv[] = {"calculator", "2", "+", "3"};
    Base* test;
    EXPECT_EQ(test -> parse(argv, argc) -> evaluate(), 5);
}

TEST(ParseTEST, ParseThree) {
    int argc = 6;
    char* argv[] = {"calculator", "2", "", "5", "+" , "3"};
    Base* test;
    EXPECT_EQ(test -> parse(argv, argc) -> evaluate(), 13);
}

#endif
