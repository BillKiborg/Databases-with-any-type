#include <iostream>
//#include "DataBase.h"
#include "User.h"
#include <type_traits>

template <typename Key, typename Value> class Template_Base {
public:
	virtual ~Template_Base() = default;
	virtual void add_data(Key, Value) = 0;	
};

template<typename A, typename B, typename C> struct convertible_selector {
	using Type
		= std::conditional_t<std::is_convertible<A, B>::value, B,
		std::conditional_t<std::is_convertible<A, C>::value, C, A>>;
};

class Base {
public:
	virtual ~Base() = 0;	
	template <typename Key, typename Value> void add(Key key, Value val) {

		using Key_Type = convertible_selector<Key, std::string, double>::Type;
		using Value_Type = convertible_selector<Value, std::string, double>::Type;

		auto database = dynamic_cast<Template_Base<Key_Type, Value_Type>*>(this);		

		if (database) {
			database->add_data(key, val);
			return;
		}
		std::cout << "База не существует\n";

	}
};
Base::~Base() = default;

class Specific_Base : public Template_Base<std::string, std::string>, public Base {
private:

public:
	
	void add_data(std::string, std::string) override {
		std::cout << "Specific Data\n";
	}

};

class User {
private:
	Base* database = nullptr;

public:
	template <typename Key, typename Value> void set_dataBase(Template_Base<Key, Value>* new_dataBase) {
		database = dynamic_cast<Base*>(new_dataBase);
		std::cout << (database ? "База добавлена\n" : "Не удалось добавить базу\n");
	}

	void use() {

		if (database) {
			database->add("123", "Value");
		}

	}

};

int main() {
	setlocale(LC_ALL, "rus");	

	User user;
	user.set_dataBase(new Specific_Base);
	user.use();	

	return 0;
}