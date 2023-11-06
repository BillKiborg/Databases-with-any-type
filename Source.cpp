#include <iostream>
#include "Templ.h"
#include <any>
#include <type_traits>

class Base {
public:
	virtual ~Base() = default;
	virtual void method() = 0;
};

template <typename T> class Mixin : public Base {
public:
	void method() override {
		static_cast<T*>(this)->spec_method(1);
	}
};

class Up_Base : public Mixin<Up_Base> {
public:
	template <typename Type> void spec_method(Type val) {
		std::cout << "Spec Method: " << val << "\n";
	}
};

int main() {
	setlocale(LC_ALL, "rus");
		
	Base* base = new Up_Base;
	base->method();

	/*User user;
	user.set_database(new String_DataBase);
	user.use();*/

	return 0;
}