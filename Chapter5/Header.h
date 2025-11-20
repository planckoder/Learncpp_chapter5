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

// BAD PRACTICE: never use a std::string_view as the return value of a function, if you return a local std::string.
std::string_view get_bool_name(bool b);

// YOU CAN: using a std::string_view as the return value of a function, if you return a C-style string (it is not destroyed)
std::string_view get_bool_name2(bool b);

// YOU CAN: using a std::string_view as a return value, if you return a std::string_view parameter
std::string_view first_alphabet(std::string_view a, std::string_view b);


#endif