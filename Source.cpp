#include <iostream>
//#include "DataBase.h"
#include "User.h"
#include <type_traits>

template <typename Key, typename Value> class Template_Base {
public:
	virtual ~Template_Base() = default;
	virtual void add_data(Key, Value) = 0;
};

class Base {
private:
	Base* base = nullptr;
public:
	virtual ~Base() = default;
	template <typename Key, typename Value> void set(Template_Base<Key, Value>* db) {

	}
	template <typename Key, typename Value> void add(Key, Value) {
		auto database = dynamic_cast<Template_Base<Key, Value>*>(base);
		std::cout << (database ? "База существует\n" : "База не существует\n");
	}
};

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
			database->add(std::string{ "Key" }, std::string{ "Value" });
		}

	}

};

int main() {
	setlocale(LC_ALL, "rus");

	User user;
	user.set_dataBase(new Specific_Base);
	user.use();

	/*User user;
	user.set_database(new String_DataBase);	
	user.run();*/

	return 0;
}