#include "Header.h"

#define skip

int main()
{
#ifndef skip
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

	int m4{cmin(5, 6)};				// OK: may evaluate at runtime or compile-time
	const int m5{cmin(5, 6)};		// OK: may evaluate at runtime or compile-time
	constexpr int m6{cmin(5, 6)};	// OK: MUST evaluate at compile-time
	

/*************************************** 5.7 - Introduction to std::string ***********************************************************
*	This is a C-style string :
*/
	std::cout << "Hello world!" << '\n';
/*	They're fine to use, but in some cases they behave quite oddly (assez étrangement), and are best avoided (sont à éviter):
*		- It's hard to work with because with can assign to this string a new value.
*		- It can be dangerous because if we copy a large C-style string into the space allocated for a smaller C-style sting, 
*		  unedefined behaviour will result.
*	Fortunately, C++ has introduced new types for strings: std::string and std::string_view. In fact they're not really a fundamental
*	type, but instead a class type (we'll cover it later).
* 
*	To use "std::string", me must add at the top of the file it's header: #define <sting>. To create an object, we can simply use 
*	"std::string" keyword to initialize an object of this type. We can do assignements with it, and even print the object using
*	std::cout. However, numbers in a string are treated as text, so we can't do mathematical manipulations. 
*	And the neatest thing (la chose la plus chouette) about std::string, is that it can handle the lenght of a sting by itself!
*	This is what make this type very powerful! By this way you can write verrrryyyyy long strings, and even if you haven't enough
*	memory, you can use the dynamic memory allocation, to allocate more memory (covered later).
*/
	std::string surname{"Ragin"};			// We can initialize a sting using "std::string"
	surname = "Rhimi";						// We can assign another string to the object
	std::cout << "My surname is : " << surname << '\n';		// We can print this string
	std::string ID{ "45" };					// Numbers are treated as text
	std::string nothing{};
	std::cout << "[" << nothing << "]" << '\n';				// If we have nothing in the string, it will print nothing
	std::string text{ "short" };			// This is a short text. It contains 6 characters (whose one is a null-terminator)
	text = "And this is long";				// And here's 17! We changed the lengh of our string!
	std::cout << text << '\n';

//	However, std::cin may yield (peut donner) some problems! Consider the folowing examples:
	std::cout << "Your name: ";
	std::string name{};
	std::cin >> name;
	std::cout << "Your favorite color: ";
	std::string color{};
	std::cin >> color;
	std::cout << '\n' << "Name: " << name << " Color: " << color << '\n';
/*	If you wrote you surname, and then your first name, you will discover that you first name was assigned to the string "color"!
*	And that's normal: std::cin, with operator >>, only returns characters up to the first whitespace it encounters. Any other
*	characters are left inside std::cin, waiting for the next extraction (in our case, std::cin for the color).
*	If we want to enter all the line, we should use the function std::getline() instead. This function is already included in the 
*	header <sting>, and it takes two arguments: the first is std::cin, and the second your string.
*/
	std::cout << "Your name: ";
	std::string nameB{};
	std::getline(std::cin >> std::ws, nameB);			// The function getline, with the manipulator std::ws

	std::cout << "Your favorite color: ";
	std::string colorB{};
	std::getline(std::cin >> std::ws, colorB);

	std::cout << "Your name is: " << nameB << "	and your favorite color is: " << colorB << "\n";
/*	Now, all is working! But there's one thing we must explain, and that's the manipulator "std::ws". In order to better understand
*	it, consider the following example: 
*/
	std::cout << "Tell me your house nummber: ";
	short int house_num{};
	std::cin >> house_num;

	std::cout << "Tell me your street: ";
	std::string street{};
	std::getline(std::cin, street);						// note: there isn't the manipulator std::ws

	std::cout << "Your adress is: " << house_num << ", " << street << '\n';

/*	Now, you'll see that the string street hasn't been asked, and hasn't been printed. That's because the previous std::cin captured
*	the character '\n', the character newline (when you pressed enter). So when we enter 34 for example, std::cin will see '34\n'
*	instead. It will extract 34, leaving the newline character behind for later. When the function "getline" want to extract a 
*	string, it sees that there's already the newline character '\n' waiting in std::cin. So according to him we already entered an
*	empty string.
*	The extraction operator >> ignores leading whitespaces (espaces blancs au début), such as the newline character, but the
*	"std::getline()" function well. So to bypass this problem, we use the manipulator std::ws, which helps us to ignore the 
*	leading whitespaces.
*	The best practice is to already use std::ws manipulator in the function std::getline(). You must put it for each function, 
*	because it's not preserved accros calls.
* 
*	If you want to know the lengh of your string, you can use the function length(). This function returns the number of characters
*	without the implicit null-terminator. The returned type is an unsigned integer, so if you want to assign this value to an int, 
*	you must use the "static_cast" to convert the type.
*	But what's more interesting, the synthaxe for this function is slightly different. Until now we've seen this :
*	function(object). But the "length()" function is a member function. That means it's declared inside of std::string, and the
*	argument is sent by this way: object.function(). We'll talk more about these functions later.
*/
	std::string book{ "Dune" };
	size_t length{ book.length() };
	std::cout << "In Dune there are " << length << " characters." << '\n';
	//int size{ length };							// lenght is an unsigned integer, I can't assign it to an integer
	int size{ static_cast<int>(length) };			// but we can change the type by using static_cast
	std::cout << -size * 2 << '\n';					// it's working! We have a signed integer!
#endif
/*	But although std::string has may advantages, it has one major drawback: it is expensive. Every time you initialize a string, it
*	copies each character form the C-style string into its own memory, which can be expansive in time. Moreover, when a std::string
*	is passed to a function by value (so as an argument), it must copy the string to the function.
*	So the best practice is to avoid to pass a string to a function by value (we'll see how in the next chapter).
*/
	std::string long_txt{ "This is a very long string" };	// Expensive, because it must copy each character and allocate memory
	std::string word{ "My text" };
	print_text(word);							// that's a very bad practice, because we must copy the string into the function
												// so finally, to strings coexist, and that's could be very expansive in memory

/*	You may expect that for returning a string, using std::string, by value to the caller, it will be also expensive, however it's not
*	the case. You can return an std::string in these 3 cases:
*		- If you return a local string from the function
*		- If you return a std::string, that has been returned previously by another function
*		- If it's a tempory string created as a part of the return statement
*	However, if you return a string that already exists, that can be slow since now we get two strings.
*/
	case1();			// Okay, it doesn't copy the local string into the caller, because it construct the string directly in
						// the caller's return slot. (in other words, case1(); is transformed into the string that has been returned)
	case2();			// Okay, for the same reason
	case3();			// Okay, for the same reason
	case4();			// BAD: the returned string already exists => it's the string "already_here". So we have a copy of this string

/*	Until now we used a std::string with a double-quoted string literals, which is a C-style string literal (e.g. "Hello"). But we can
*	also create string literals of type std::string by using a suffix "s", placed after the double-quoted string literal. The s must 
*	be lower case:
*/
	using namespace std::string_literals;	// it's an esay acces to the suffix s
	std::cout << "Hello!"s << '\n';			// here is an std::string literal
	std::cout << "Bye" << '\n';				// And here we have a C-style string
/*	You probably won't use it, but it can be useful in some situations (we'll see it later).
* 
*	Also it's possible to create constexpr std::string strings, but they are badly supported in the latests C++ versions, so use 
*	std::string_view instead.
* 
**************************************** 5.8 - Introduction to std::string_view ******************************************************
*	Consider the following examples:
*/
	int alpha{ 8 };			// the value 8 is copied into the memory allocated for variable alpha. For fundamental types it's fast
	std::string hello{ "hello world!" };	// But for strings it far more slower! It must copy each character into the memory
	print_text(hello);						// and this is even worse! we copy the string 2 times: 1 time is the initalizer, and the
											// second time in the function
/*	So using always std::string type may be unefficient. That's why we introduce another type: std::string_view
* 
*	To adress this issue, we should use "std::string_view", which lives in the header <string_view>. But std::string_view is a new 
*	feature, that was implemented in C++17. So if you have another version of C++(It was my case, my version was C++14), rigth click 
*	on your program in the solution explorer (normally in the window at the right of your screen. Don't choose the program.cpp file,
*	but the file wich is situated at the top), choose "properties", and in the window that appears, click on the triangle situated at
*	the left of "C/C++". It opens a list, and you must choose the option "Language". Then you can choose your version in the "Norm of 
*	language C++".
*/
	printSV(hello);								// Is better to use this function, because it doesn't copy the string
	std::string_view forSV{ "Hello again" };	// This time, we don't even copy the string into the variable "forSV" !
	printSV(forSV);
	
/*	So the function printSV is far more better that the function print_text, because we don't create a copy of the string in the 
*	function. Also, we can use the std::string_view during initialization, which avoid us to copy string at this point too.
*	So the best practive is to use std::string_view when we need a read-only string (so if you don't need to modify it), especially
*	for function parameters.
*	
*	Another neat thing (soigné) about std::string_view is how flexible it is: you can initialize it using a C-style string, an
*	std::string variable or even another std::string_view variable!
*/
	std::string_view s1{ "C-style string" };

	std::string s2{ "std::string" };
	std::string_view s3{ s2 };
	
	std::string_view s4{ s3 };

	std::cout << s1 << '\n' << s3 << '\n' << s4 << '\n';

/*	Also, it is useful to know that when you pass a C-style string or a std::string object by value in a function, it implicitly 
*	convert them to a std::string_view. Therefore, a std::string_view parameter will accept  arguments of type C-style string, 
*	std::string and std::string_view
*/
	printSV("C-style string converted to std::string_view");
	printSV(s1);
	printSV(s3);

/*	however, C++ doesn't allow an implicit conversion of std::string_view to a std::string. This is to prevent making an expansive
*	copy by accident, when you pass your std::strin_view argument to a std::string paramater.
*	To by pass this problem, you can initalize a std::string using your std::strin_view, and then pass it by value, or you can
*	convert it to a std::string type, using static_cast.
*/
	//print_text(s3);							// will occur an error, since the conversion is disallowed
	print_text(static_cast<std::string>(s3));	// but we can do that

/*	ONE IMPORTANT THING: when we assign a new string to std::string_view, it doest's change the prior std::string that had been viewed.
*	Consider the following example:
*/
	std::string my_house{"It is very big"};
	std::string_view another_house{ my_house };
	std::cout << another_house << '\n';

	another_house = "Now it's smal";
	std::cout << another_house << '\t' << my_house << '\n';		// the std::string_view has changed, but not the std::string

/*	Also it's possible to create string literals of type "std::string_view". To do that, write first the access to the to the literals
*	: "using namespace std::string_view_literals", and then put the suffix "sv" after you C-style strings (which are double-quoted).
*/
	using namespace std::string_literals;			// this is the access to the std::string literals
	using namespace std::string_view_literals;		// and this for std::strin_view

	std::cout << "C-style string" << '\n';
	std::cout << "std::sting"s << '\n';
	std::cout << "std::string_view"sv << '\n';

/*	And unlike std::string, constexpr std::strin_view has full support. So when we need a string symbolic constant that will be 
*	replaced at compile-time, the preffered choice is constexpr std::string_view.
*/
	constexpr std::string_view con_str{ "I'm constant" };

	std::cout << con_str << '\n';		// con_str will be replaced at compile-time


/*************************************** 5.9 - Introduction to std::string_view (part 2) *********************************************
*	It's our first time when we encounter a view type with std::string_view. So this chapter will explaine what does this type do, and
*	when we should use std::string or std::string_view.
* 
*	So imagine you want to draw a picture of a bike. The first option is to buy a new bike in a market, and that has many advantages:
*	you can decorate your bike, you can move it and you can always guarantee that your bike will be always avaible. But there are also
*	some downsides to this choice: you must periodically maintain it, when you don't want it any more you have to properly dispose of
*	it (s'en débarasser correctement), and the most imporant: it's expensive of buying a new bike!
*	The other option is to look at the bike of you neighboor, that you can see from your window. The benefits are that you can draw
*	pictures of this bike, but without being responsible of it, or maintain it periodically. You can also simply close your curtains
*	(rideaux) and move it from your life. But there is also some potential downsides: while you'll be viewing the neighboor's bike, he
*	can change it or move it of your view altogether (tout à fait). So you may end with a view of something unexpected.
* 
*	So according to this example, std::string is the first case. When we initialize a std::string using an initializer (a C-style 
*	string for example), it makes an expensive copy of it. It has some benefits:
*		- The memory is reserved to the objet and guaranteed to exist for as long the object does.
*		- The initialized object has it own independent value to acces and manipulate later.
*		- The nex object is no longer reliant on the initializer in any way. And it's great, because can't be generally trusted after
*		  the initialization. For example if we return a value from a function to the caller, if it was a temporary object will be  
*		  directly destroyed, and if it was a variable, the caller can do whatever it wants, including modify or destroy it.
*	The downsides of making a std::string are the following:
*		- We must make an expansive copy!
*		- We must manage the acces to the string data
*		- We must properly disposing of string data when the std::string object	is destroyed.
* 
*	Now let's see an example of the previous lesson, to understand when we can use a copy of a string:
*/
	std::string s5{ "Should the function make a copy ?" };

	print_text(s5);

/*	So here we used the parameter of type std::string instead of std::string_view. But to know if we can use std::string, ask 
*	yourself these 3 questions:
*		- Could s5 be destroyed while s is still using it? (Here no)
*		- Could s5 be modified while s is still using it? (Here no)
*		- Could s modify the string in some way the caller would not expect? (Here no)
*	If the answer to these three questions is no, then use std::string_view!
* 
*	Now let's talk about std::string_view. It creates an unexpensive view of the initialization string, and then it can be used
*	whenever (chaque fois) access to the string is required. So here are the benefits:
*		- It is unexpensive
*		- it cannot modify the object its viewing
*		- Having multiple viewers for a single object is fine
*		- When the view is destroyed, the object is not affected
*	BUT, there are some thing you must ensure:
*		- The string being viewed CANNOT be modified or destroyed while the view is still being viewed. It can lead to unexpected 
*		  or undefined behaviour.
* 
*	std::string_view is best used as a read-only function parameter. This allow us to pass C-style string, std::string and 
*	std::string_view argument without making a copy, as the std::string_view will create an view of it. Since the "s" parameter is
*	created, initialized, used and destroyed before the control returns to the caller, there's no risk the string that is viewed will
*	be modified or destroyed.	
*/
	std::string norm_str{ "I'm a simple string" };
	printSV(norm_str);

/*	NOTICE FOR ADVANCED READERS: prefer std::string_view instead of const std::string& for the function parameters. We'll cover it
*	in the lesson 12.6.
* 
*	Now let's see 3 examples of a bad using of std::string_view:
*	The first one, is when we initialize a std::string_view object inside a nested block (block imbriqué, don't worry about what it is)
*	The problem is that the string which is viewed by std::string_view is destroyed at the end of the nested block, and so we get an
*	undefined behaviour.
*/
	std::string_view s6{};
	{
		std::string s7{ "I'm in a nested block!" };
		s6 = s7;
	}
	std::cout << s6 << '\n';	// we have an undefined behaviour (in my case the program prints white lines), because the object (s7)
								// that the s6 was viewing has been destroyed at the end of the nested block.

/*	Another variant of this issue is when we initialize a std::string_view using a std::string variable returned from a function. The
*	problem is that return values are temporary objects, so when we want to print the std::string_view, the value to which it was 
*	pointing is already destroyed. To by pass this problem, you can copy it to use it later (with std::string), or simply directly 
*	use this value.
*/
	std::string_view s8{ case1() };		
	std::cout << s8 << '\n';			// At this point, the viewed object is already destroyed. We have an undefined behaviour

/*	And the last non-obvious example is when we initialize a std::string_view using a std::string literal s. So when we add the suffix
*	"s" to a C-style string, we get a temporary std::string, that will be then destroyed. The std::string_view is left dangling 
*	(suspendu), and we get an undefined behaviour.
*/
	using namespace std::string_literals;
	std::string_view s9{ "std::string"s };
	std::cout << s9 << '\n';				// the std::string litteral is destroyed, leaving the std::string_view object dangling

/*	In fact, std::string litteral (s) is the single string that is temporary. But you can whithout fear initialize with:
*		- A C-style litteral
*		- A std::string_view litteral (sv)
*		- A C-style object								, as long as it outlives the view
*		- A std::string object (std::string)			, as long as it outlives the view
*		- A std::string_view object (std::string_view)	, as long as it outlives the view
* 
*	Also, don't forget that if you change the string at which the std::string_view is viewing, it leads to an undefined behaviour.
*/
	std::string s10{ "Oh, macarena!" };
	std::string_view s11{ s10 };

	s10 = "macarena, macarena!";
	std::cout << s11 << '\n';			// and again an undefined behaviour! s11 was viewing s10, but we changed it.

/*	So remember: changing a std::string is likely to invalidate all views into that std::string
* 
*	Now, let's see how to reinvalide invalide std::string_view's (like in the examples just above). The solution is simple: you just
*	have to assign the invalidated std::string_view object a valid string to view. Look how to do so:
*/
	std::string s12{ "Matushka zemlya!" };
	std::string_view s13{ s12 };

	s12 = "Belaya beriezynka!";		// At this point s13 is invalid since s12 has been destroyed. s13 is dangling.

	std::cout << s13 << '\n';		// Undefined behaviour

	s13 = s12;						// But now we're reinvalidating s13. Now it's viewing again the string s12.

	std::cout << s13 << '\n';		

/*	
*/


	return 0; 
} 
