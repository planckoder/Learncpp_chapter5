#ifndef HEADER
#define	HEADER

#include <string_view>
#include <format>	// for std::format()
#include <print>	// for std::println()
#include <bitset>
#include <iostream>
#include <string>

void print_five(const short x);

int user_val();

int three();

int min(int x, int y);

constexpr int cmin(int x, int y);

void print_text(std::string s);

std::string case1();
std::string case2();
std::string case3();
std::string case4();

void printSV(std::string_view s);

#endif