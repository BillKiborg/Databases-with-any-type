#pragma once

template <typename Key, typename Value> class DataBase {
public:
	virtual ~DataBase() = default;
	virtual void add_data(Key, Value) = 0;
};

class String_DataBase : public DataBase<std::string, std::string> {
public:
	void add_data(std::string, std::string) override {
		std::cout << "Execute String\n";
	}
};

class User {
private:

	struct Base {
		virtual ~Base() = default;			
	};

	template <typename Key, typename Value>	struct Up_Base : public Base, public DataBase<Key, Value> {		

		DataBase<Key, Value>* database = nullptr;

		Up_Base(DataBase<Key, Value>* db) : database{ db } {
			std::cout << "UpBase Create\n";			
		}

		void add_data(Key key, Value val) override {
			database->add_data(key, val);
		}

	};

	Base* data = nullptr;

	template <typename Key, typename Value> void add_data(Key key, Value value) {

		std::cout << (data ? "DB: Exist\n" : "DB: NotExist\n");
		try	{
			Up_Base<Key, Value>* ptr
				= dynamic_cast<Up_Base<Key, Value>*>(data);

			std::cout << "Type ptr: " << typeid(ptr).name() << "\n";

			ptr->add_data(key, value);

		}
		catch (std::exception& exc) {
			std::cout << exc.what() << "\n";
		}
	}

public:

	template <typename Key, typename Value>	void set_database(DataBase<Key, Value>* database) {

		std::cout << "DataBase: " << typeid(*database).name() << "\n";	
		data = new Up_Base{ database };
	}

	void use() {
		add_data(std::string{ "Key1" }, std::string{ "Value1" });
	}

};