#include <string_view>
#include <format>	// for std::format()
#include <print>	// for std::println()
#include <bitset>
#include <iostream>


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

constexpr Cmin(int x, int y)
{
	if (x < y)
		return x;
	else
		return y;
}

int main()
{
/************************************** 5.1 — Constant variables (named constants) ***************************************************
*	A constant is a value that may not be changed during the program's execution. There are two types : named and litteral constants.
*	A named constant is a value wich is associated with an identifier, and a litteral is not.
*	There are 3 ways to define a named constant : constant varibles, object-like macros (introduced in lesson 2.10) and enumerated 
*	constants.
* 
*	A constant variable are needed when we want to use values that will never change, for exeample pi, or gravity on earth (9.81).
*	These variables are defined with the word const before or afer the willed type, but the best practice is to write is before. Also
*	a constant must be initialized directly, and cannot be changed.
*/
	const char letter{ 'c' };
	//	letter = 'a';			 will occur an error; you can't change the value
	const double GRAVITY_ON_EARTH{ 9.81 };		// No problem, and moreover we use the convetion of naming from C.
	float const pi{ 3.14f };					// This is not the best practice. You should put const before the short type.
/*	The convention of naming varies from developer to developer, but the most common practice is to use the convention for constants
*	from C : upper-case letters with undescores between words. But you can also use the convention for basic variables.
* 
*	In C++ it is possible to use consts for value parameters in function. It helps the compiler to ensure that the value of the 
*	parameter didn't changer during the execution of the code. What's interesting, you don't need to initialize the const variable, 
*	and the variable is destroyed at the end of the function. However it is preffered not to use this kind of parameters(only if you
*	pass arguments like adresses or references).
*/
	print_five(5);
	print_five(6);
/*	It is also possible to return constant values, but it can result in lower performance. Avoid returning consts.
* 
*	You should use constant variable as often as possible for these reasons : it reduces bugs, optimizes the program and makes the 
*	program less complex.
* 
*	We covered also another kind of named constants : the object-like macros with text subsitution. There are some reasons you  
*	should prefer variable constants than macros :
*		1)	They don't lead the same rules of scope, which can lead to errors
*		2)	It's more difficult to debug programs when they are used, because the debbuger often can see them.
*		3)	They behalve differently than everything else in C++
*	So prefer using constant variables.
* 
*	Also it's interesting to know that the key word "const" is a type qualifier, that modifies how the type behalves. In C++ there
*	are 2 type qualifier : const and volatile. But this information is not so important.
*
*************************************** 5.2 — Literals ****************************************************************************
*	A litteral is a value that is inserted directly in the code. Sometimes they are called constant litteral because their meaning
*	cannot be redefined (5 is 5). Examples :
*/
	int number_den{ 5 };	// five is an integer litteral
	std::cout << "Hello den" << '\n';	// "Hello den" is a C-style sting litteral.
/*	All litteral have their type, which is deduced from their value (integer, boolean, double, char, string).
*	If the default type of a litteral is not as desired, you can change it by adding a suffix. You can see them all here:
*	https://www.learncpp.com/cpp-tutorial/literals/
*	But we've already seen a suffix : f for float. And in fact it's the most common suffix you will use, because the compiler 
*	cannot convert a double type (by default) to a float type, without a loose of precision. But in most cases, for other suffix
*	the program will convert the litteral with the suffix by itself.
*/
	std::cout << 5L << '\n';	// 5 is type long. Also it is prefered to use the upper-case for L, instead of l (looks like 1)
	std::cout << 5u << '\n';	// 5 is type unsigned in
	double haha{ 5.36 };		// it's a double type
	float klkl{ 6.32f };		// it's a float type, you must use the suffix f
	double avogadro{ 6.02e23 };	// it's a litteral in a scientific notation
/*	There are also string litterals. The C-style string litteral can be identified thanks to double quotes. There are some things 
*	to know about this strange and complicated type.
*	firstly, the C-style string litteral, inherited from C, always has an additional character '\0', that represents the end of the
*	string.
*	Secondly, C-style stings are objects that are guarenteed to exist for the entirety of the program, unlike std::string or 
*	std::string_view.
*************************************** 5.3 — Numeral systems (decimal, binary, hexadecimal, and octal) *******************************
*	There are 4 numeral system available in C++ : binary, decimal, hexadecimal(16 based) and octal (8 based).
*	In octal system we only have these digits : 0, 1, 2, 3, 4, 5, 6, 7. So 8 digits in all. The counting in this system would be 
*	something like this : 1, 2, 3, ..., 7, 10, 11, ... So we skip 8 and nine and  we go directly to 10. To use octal decimal, use the 
*	prefix "0" in front your number.
*/
	int octal{ 012 };
	std::cout << "12 octal in decimal system is : " << octal << '\n';	// The program prints 10
/*	We print 10 instead of 12 because the numbers are output decimal by default, and 012 octal = 10 decimal. Octal is very hardly 
*	used, so it's better to avoid this numeral system.
* 
*	The hexadecimal is 16-based, and we count like this : 0, 1, 2, ..., 9, A, B, ..., F, 10, 11, ..., 19, 1A, 1B, ...
*	To initialize a hexadeciamal number, print the prefix '0x'.
*/
	int hexa{ 0xF };
	std::cout << "F in decimal is : " << hexa << '\n';	//	The program prints 15
/*	If you want to see the table of numbers , for each system, go to this page :
*	https://www.learncpp.com/cpp-tutorial/numeral-systems-decimal-binary-hexadecimal-and-octal/
* 
*	Hexadecimals are often used to represent binary, for example for adresses or memory. We use hexadecimals because they have 16 
*	digits, and so we can represent a 4 bite binary number with one hexadecimal digit. By this way, the binary number is easier to 
*	read. (e.g. : OO10 is 2 in hexadecimal system.)
* 
*	Before C++ 14, we could't use binary literals, so the programmers used this workaroud (solution de contournement), which is useful
*	to know if you encounter it in some old code.
*/
	int bin{};	//let's assume 16 bits ints
	bin = 0x0005;	// assign binary 0000 0000 0000 0101
	bin = 0xFB05;	// assign binary 1111 1011 0000 0101
/*	But know we can also use binary literals by using the '0b' prefix
*/
	bin = 0b1;			//	assign binary 0000 0000 0000 0001
	bin = 0b11110000;	// assing binary 0000 0000 1111 0000
/*	We can also use a digit separator in the case above, like this : 0b1111'0000. It's purely visual, it doesn't influence the value.
*	But you can put the digit separator before the number, it will occur an error.
* 
*	As we've seen before, by default C++ outputs decimal values, but fortunately you can change it by using std::dec, std::oct and
*	std::hex I/O manipulators. Of course the change persists until the end, unless you reuse the manipulator.
*/
	int a{ 15 };
	std::cout << a << '\n';
	std::cout << std::oct << a << '\n';
	std::cout << a << '\n';
	std::cout << std::hex << a << '\n'; std::cout << std::dec << a << '\n'; 
/*	If you want to print a binary number, you must add a header called <bitset>, and create variables by using type "std::bitset".
*	You also have to indicate the amount of bits you want to store (std::bitset<HERE>). You can initialize with any format (binary
*	hexadecimal, decimal, octal).
*/
	std::bitset<4> bin1{ 0b1011 };
	std::bitset<4> bin2{ 0xB };
	std::cout << bin1 << '\n' << bin2 << '\n';
	std::cout << std::bitset<4>{5} << '\n';		// We can even create temporary objects
/*	But in C++ 20 and 23 we have better options to print binary number, by using std::format() and std::println. To use them, you must
*	add the headers <format> and <print> respectively. inside the parentheses, you can write "{:b}, YOUR NUM" to have the binary num,
*	or "{:#b}, YOUR NUM", if you want to have a prefixed 0b-digit.
*/
	/*std::cout << std::format(":b\n", 6);
	std::cout << std::format(":#b\n", 5);
	std::println(":b" ":#b", 6, 5);*/

/*************************************** 5.4 — The as-if rule and compile-time optimization ******************************************
*	The optimization is a process of modifying a software to make it work more effeciently. When can do it by different ways :
*		- Use a program called "profiler" that can see the overal performance, and then optimize it by hand (à la main). But for the
*		reason it is slow, the programmer focus on high-level improvements, which will have a large impact.
*		- By using a program called "optimizer". Modern C++ compilers automatically optimize the program, what let the programmer to
*		focus on readability and maintenance. These optimizers work at low-level. So it will for example change the statements to 
*		optimize the program.
* 
*	The compilers in C++ use the "as-if rule". It says that the compiler can change and optimize the code, but doesn't change the
*	observable result.
* 
*	Let's see an example of optimization. Below we have a code that evaluates the variable "opt" to 7, by do the addition 3+4. That's 
*	mean that if we run this program a million times, it will reevaluate the result each time. Hopefully the compiler optimize this.
*/
	int opt{ 3 + 4 };
	std::cout << opt << '\n';
/*	When the compiler fully or partially evaluates an expression, it's called : compile time evaluation. It allows the program to be
*	faster during the runtime. Let's see some optimizations for the "compile time evaluation".
* 
*	The constant folding is a form of a compile time evaluation. It's a technique where the compiler replace an expression by it's 
*	result, as the example above : it replaces the expression 3 + 4 by 7, so the program has no more to do this calculation. It works
*	also for subexpression, as this one :
*/
	std::cout << 3 + 4 << '\n';
/*	Another technic that uses the compiler is the constant propagation. When you initialize variable, and then output it, the program
*	will require two memory access : the first to store the value, and the second to fetch (chercher) it out. So at the compile time
*	the compiler will replace any variable by its value.
*	But to help the compiler to optimize the code, it is recommanded to use constant variables, when the variable don't need to be
*	changed, because the compiler has a guarantee the variable will be the same all along the code.
*/
	int x{ 4 };
	std::cout << 4 << '\n';		// This is what the program will look like after the compile time. The variable x is replaced by 4.
/*	The dead code elimination is a technique that removes all the unecessary code, without changing the behaviour of the program. So
*	for example if I would write the program above, the compiler would remove the initialization of the variable x, because it's never
*	used anywhere.
*	
*	By default, for all programs the optimizations for the compiler are turned off. It's because while develloping a program with 
*	optimizations, it may be hard to debug it : the variable is replaced by its value, some part of code is removed, etc... So it 
*	would be a real challenge to fix an issue if it is due to the compiler's optimizations.
* 
**************************************** 5.5 — Constant expressions ******************************************************************
*	Unfortunately, the compiler doesn't say us which part of code it had optimized and which not during the compile-time: we don't get
*	a feedback. However, in C++ it is possible to explicitly execute some expression during the compile-time, by using some language
*	features. Using these features is called "compile-time programming". By this way, the program become both more effecient and 
*	higher in quality (less bugs). There are 4 fundational features :
*		- constexpr variables
*		- constexpr functions
*		- templates
*		- static_assert
* 
*	A constant expression is non-empty sequence of literals, constant variables, operators and function calls, that are executed 
*	during the compile-time. They form the backbone of the compile-time evaluation in C++. It can be a literal (4), an operator with 
*	constant expression operands (2+7), const integral variables whith a constant expression initializer (int x{6}; ) (but constexpr
*	is preffered) , constexpr variables and finally constexpr function calls with constant expression arguments. Some examples :
*/
	// Literals can be used in constant expression
	6;								// constant expression
	6.54;							// constant expression
	"word";							// constant expression
	
	// Most operators that have constant operands can be used in constant expression
	8 * 5.6;
	1 + 6;
	sizeof(int) - 2;				// sizeof(int) can be determined at the compile time

	// The return values of non-constexpr functions can only be used in runtime
	user_val();						// runtime expression
	three();						// runtime expression, even though the return expression is a constant expression

	// Operators whitout constant expression operands can only be used in runtime
	std::cout << 7;					// can only executes in runtime

	// Const integral variables with a constant expression initializer can be used in constant expressions
	const int aa{ 7 };				// constant expression
	const int b{ aa };				// constant expression, because the initializer is also a constant expression
	const long c{ b - 5 };				// operator - use constant operands, so it's a constant expression

	// Other variables can't be use in constant expressions, even if they have a constant expression initializer
	int d{ 9 };						// Not const
	const int e{ d };				// hasn't a constant expression initializer
	const double f{ 9.56 };			// not an integer => can't be used in constant expression

/*	You may think that constant expressions are always evaluated at compile time, but counterintuitively, it's not the case. In fact, 
*	"the compiler is only required (tenu) to evaluate a constant expresssion at compile-time in context that require a constant
*	expression.". That means, it will evaluate a constant expression only if it's necessary, otherwise, it could choose to evaluate it
*	or not. Examples :
*/
	int g{ 3 + 4 };					// g is not a constant expression (not a const), so evaluating the constant expression "3+4" is 
									// necessary in this context. The compiler may choose to evaluate it or not at compile time.
	const double long h{ 3 + 4 };	// In this case, if we don't evaluate the constant expression "3+4", the compiler won't be able to
									// initialize the constant variable h, so here the compiler MUST evaluate 3+4
/*	However, modern compilers will usually evaluate constant expressions, even if they aren't required, when optimizations are enabled.
*	There are two main reasons for this behaviour :
*		- It's easier to debug when we have less compile-time evaluations (imagine if the compiler did a wrong calculation).
*		- It gives more flexibility to the compiler to optimize as it sees fit (comme bon lui semble).
* 
*	But you may wondering, why compile time expressions must be constant? Look at this example: 
*/
	int i{ 5 };						// At this point the value of "i" is known, so there isn't any problem
	std::cin >> i;					// But now, "i" can't be evaluated at compile-time
/*	Thus, a single line of code which can't be evaluated at compile-time will violate the requirement that such an expression must 
*	always be capable of being evaluated at compile. If the compiler had to know when a variable can be evaluated at compile-time, and
*	when not, it would have added a lot of complexity to the compiler. For these reasons, only constant objects can be evaluated at 
*	compile-time.
*/
/*************************************** 5.6 - Constexpr variables *******************************************************************
*	Now let's create our own constant variables! The first way to do it is to use the keyword "const". This "const" variable, with an
*	integral type and a constant expression initializer can be used in a constant expression. But there are some challenges with it:
*		- Firstly, it's not immediatly clear whether the variable is usable in a constant expression or not. So it means we have to go
*		  inspect the definitions of those initializer and infer (déduire) what case we're in.
*/
	int variableA{ 5 };		// Obviously not a constant expression
	int bb{};
	const int variableB{ bb };			// Not a constant expression since the initializer is non-const
	const int variableC{ 5 };			// It's a constant expression
	//const int variableD{ someVar };		// We can be sure whether variableD is usable in a constant expression or not
	//const int variableE{ function() };	// the same notice as above

/*		- Secondly, const doesn't inform the compiler that we require a variable usable in a constant expression. Instead, it silently
*		  creates a variable that can only be used in runtime expression.
*		- And finally, the "const" keyword does not extend to non integral variables.
* 
*	Fortunatly, we can use the keyword "constexpr" to ensure we get a compile-time constant variable. A constexpr variable is always a
*	compile-time constant, which means it must be initialized with a constant expression, otherwise it will occur an error. Examples:
*/
	constexpr double sum{ 5 + 2.5 };	// OK, because 5+2.5 is a constant. And as you can see, we can use non-integral values
	constexpr double sum2{ sum };		// OK, because sum is a constant expression
	int age{};
	std::cout << "enter your age : " << '\n';
	std::cin >> age;
	//constexpr int user_age{age};		// This will result an error (C2373), because "age" can't be determined at the compile-time
	//constexpr int num_test{three};	// The return of this function is not a constant expression

/*	Now, let's see the difference between const and constexpr variables :
*		- Const :
*			Means that the value of the variable can't be changed after the initialization. The initializer can be constant or not. 
*			The const object can be evaluated at the runtime.
*		- Constexpr :
*			Means that the object can be used in a constant expression. The value of the initializer must be known at the 
*			compile-time. The constexpr object can be evaluated at runtime or compile-time. So constexpr variables are implicitly 
*			const.
*	The best practices of using these constant types is :
*		- Variables whose initializer ia a constant expression should be declared as constexpr.
*		- Variables whose initializer is not a constant expression should be declared as const.
* 
*	What about const and constexpr function parameters? They are initialized in a function at runtime, which leads to 2 consequences:
*		- const function parameters are treated as runtime constants
*		- Function parameters cannot be declared as constexpr, since their initialization value isn't determined until runtime.
* 
*	Until now we used some specific words as compile-time expressions, or constants. But let's clearly define them:
*		- Compile-time constant:
*			A value or a non-modifiable object whose value must be known at compile-time. (e.g. literals or constexpr variables)
*		- Constexpr:
*			Keyword that declares objects as compile-time constants.
*		- Constant expression:
*			An expression that contains compile-time constants or operators/functions that support compile-time evaluation.
*		- Runtime expression:
*			Not a constant expression. (expressions evaluated at runtime)
*		- Runtime constants:
*			A value or non-modifiable object that is not a compile-time constant.
* 
*	A constexpr function is a function that can be called in a constant expression. If it's called in the intialization of a constexpr
*	variable, it MUST be evaluated at compile-time. Otherwize, it may be evaluated at either compile-time (only if all the arguments 
	are constant expressions) or runtime.
*/
	int m1{ min(5, 6) };			// OK
	const int m2{ min(5, 6) };		// OK
	//constexpr int m3{min(5, 6)};	// ERROR: min(5, 6) is not a constant expression

	int m4{min(5, 6)};				// OK: may evaluate at runtime or compile-time
	const int m5{min(5, 6)};		// OK: may evaluate at runtime or compile-time
	constexpr int m6{min(5, 6)};	// OK: MUST evaluate at compile-time
	

/*************************************** 5.7 - Introduction to std::string ***********************************************************
*/

	return 0; 
} 