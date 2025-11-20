#include "Header.h"

std::string already_here{ "I'll be copied" };	// This string is out of scope of main, so I can return it in "case4()"

// The function uses a constant argument, so we ensure the variable won't be changed.
void print_five(const short x)
{
	std::cout << x << '\n';
}

int user_val()
{
	int y;
	std::cout << "Enter an integer value : " << '\n';
	std::cin >> y;											// can only executes at runtime
	return y;												// Not a constant expression => runtime expression
}

int three()
{
	constexpr int x{ 3 };
	return x;												// this return is a constant expression, but the substitution won't be
}

int min(int x, int y)
{
	if (x < y)
		return x;
	else
		return y;
}

constexpr int cmin(int x, int y)
{
	if (x < y)
		return x;
	else
		return y;
}

// This function print a text. BAD PRACTICE, NEVER PASS AN STD::STRING IN A FUNCTION BY VALUE !!!
void print_text(std::string s)
{
	std::cout << s << '\n';
}

// returns the local string
std::string case1()
{
	std::string s{ "Hello" };	// You may think that at this point we create a string. But not, it is created at the function caller!
	// So we don't have 2 copies of the same string, the memory for it was allocated only one time.
	return s;
}

// a function that returns a string as a part of the return statement
std::string case3()
{
	return "Mama mia!";
}

// Returns a string that had been return be another function
std::string case2()
{
	return case3();
}

// Returns a string that already exists in main()
std::string case4()
{
	return already_here;
}

// This function is preffered, since we use std::string_view to pass the string by value
void printSV(std::string_view s)
{
	std::cout << s << '\n';
}

// BAD PRACTICE: never use a std::string_view as the return value of a function, if you return a local std::string.
std::string_view get_bool_name(bool b)
{
	std::string t{ "true" };
	std::string f{ "false" };
	if (b == true)
		return t;
	else
		return f;
}					// at this point strings t and f are destroyed, and we get an undefined behaviour.

// YOU CAN: using a std::string_view as the return value of a function, if you return a C-style string (it is not destroyed)
std::string_view get_bool_name2(bool b)
{
	if (b==true)
		return "true";
	else
		return "false";
}							// the C-style strings are not destroyed at the end of the function

// YOU CAN: using a std::string_view as a return value, if you return a std::string_view parameter
std::string_view first_alphabet(std::string_view a, std::string_view b)
{
	if (a>b)
		return b;
	else
		return a;
}