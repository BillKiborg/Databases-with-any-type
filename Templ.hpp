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
		template <typename Key, typename Value> void _add_data(Key key, Value val) {

			std::cout << "Base add data: " << key << ": " << val << "\n";
			static_cast<Up_Base<Key, Value>*>(this)->add_data(key, val);
		}
	};

	template <typename Key, typename Value>	struct Up_Base : public Base, public DataBase<Key, Value> {		

		DataBase<Key, Value>* database = nullptr;

		Up_Base(DataBase<Key, Value>* db) : database{ db } {
			std::cout << "UpBase Create\n";			
		}

		void add_data(Key key, Value val) override {

		}

	};

	Base* data = nullptr;

	template <typename Key, typename Value> void add_data(Key key, Value value) {

		static_cast<Up_Base<Key, Value>*>(data)->add_data(key, value);
	}

public:

	template <typename Key, typename Value>	void set_database(DataBase<Key, Value>* database) {

		std::cout << "DataBase: " << typeid(*database).name() << "\n";	
		data = new Up_Base{ database };
	}

	void use() {
		if (data) data->_add_data("Key1", "Value1");
	}

};