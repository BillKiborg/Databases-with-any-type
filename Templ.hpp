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
//-------------------------------------------------------------------------------
class User {
private:
	
	struct Base {
		virtual ~Base() = default;				
		virtual void check(Base*) = 0;
	};
	
	template <typename Key, typename Value>	struct Up_Base : public Base {		
		
		using TypeKey	= Key;
		using TypeValue = Value;

		DataBase<Key, Value>* database = nullptr;

		Up_Base(DataBase<Key, Value>* db) : database{ db } {
			std::cout << "Up_Base Create\n";			
		}		

		void check(Base* new_data) override {
			std::cout << "--Check_Derivaive\n";
			std::cout << typeid(TypeKey).name() << "\n";
			//support_check(new_data);
		}		

	};

	Base* data = nullptr;
	
	template <typename Key, typename Value> bool add_data(Key key, Value value) {
				
		using Up_Base_Type = Up_Base<Key, Value>;
		Up_Base_Type* ptr = nullptr;

		data->check(ptr);		

		return false;
	}
	//-----------------------------------------------------------------------------------------

public:
	template <typename Key, typename Value>	void set_database(DataBase<Key, Value>* database) {
				
		data = new Up_Base{ database };
	}

	void use() {
		std::cout << "Try to add data: ";
		if (add_data(std::string{ "Key1" }, std::string{ "Value1" })) {
			std::cout << "successfully\n";
		}
		else {
			std::cout << "unsuccessful\n";
		}
	}

};