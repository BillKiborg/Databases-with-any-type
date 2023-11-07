#include <iostream>
#include "Templ.h"
#include <any>
#include <type_traits>

class Base {
public:
	virtual ~Base() = default;
	template <typename Type> Type* get() {
		return static_cast<Type*>(this);
	}
};

template <typename Type> struct Up_Base : public Base {

	using DataBase_Type = Up_Base<Type>;
	using T = Type;

	T get_T() {
		return T{};
	}
	void method() {
		std::cout << "Method\n";
	}

	DataBase_Type get_data_type() {
		return DataBase_Type{};
	}

};

template <typename Type> void func(Base* base) {

	auto result = static_cast<Type*>(base)->get_data_type();
	std::cout << "Result: " << typeid(result).name() << "\n";
}

template <typename SaveType> class Saver {
private:
	using Save = SaveType;
public:
	Saver(SaveType) {
		std::cout << "Тип: " << typeid(SaveType).name() << " - сохранен\n";
	};
	template <typename Type> bool compare(Type) {
		return typeid(Type) == typeid(SaveType);
	}
};

//template <typename Compare> void run()



int main() {
	setlocale(LC_ALL, "rus");

	
	/*Saver saver{ 5 };
	saver.compare("123");*/

	/*Base* base = new Up_Base<int>;	
	std::cout << typeid(*base->get<Up_Base<int>>()).name() << "\n";
	func<Up_Base<int>>(base);*/
	
	
	/*Base* base = new Up_Base<int>;
	func<Up_Base<int>>(base);*/	

	/*User user;
	user.set_database(new String_DataBase);
	user.use();*/

	return 0;
}