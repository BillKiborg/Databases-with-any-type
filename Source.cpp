#include <iostream>
#include "Templ.h"
#include <any>
#include <type_traits>

class Base {
public:
	virtual ~Base() = default;	
};

template <typename Type> struct Up_Base : public Base {
	using T = Type;
	T get_T() {
		return T{};
	}
	void method() {
		std::cout << "Method\n";
	}
};


template <typename Type> void func(Base* base) {

	auto result = static_cast<Type*>(base)->get_T();
	std::cout << "Result: " << typeid(result).name() << "\n";
}

template <typename Type> class Class_A {
public:
	template <typename Type2> void method() {
		std::cout << "Template method\n";
	}
};

int main() {
	setlocale(LC_ALL, "rus");		

	Base* base = new Up_Base<int>;
	func<Up_Base<int>>(base);

	/*Base* base = new Up_Base;
	base->method();*/

	/*User user;
	user.set_database(new String_DataBase);
	user.use();*/

	return 0;
}