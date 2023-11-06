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

	struct Base_Mixin {	
		virtual ~Base_Mixin() = default;
		virtual void compare() = 0;
	};	
	
	struct Base {
		virtual ~Base() = default;				
		virtual void check(Base_Mixin*) = 0;
	};
	
	template <typename T> struct Mixin : public Base_Mixin {
		void compare() override {
			static_cast<T*>(this)->set_type_compare();
		}
	};
	
	template <typename Key, typename Value>	struct Up_Base : public Base {		
		
		using TypeKey	= Key;
		using TypeValue = Value;

		DataBase<Key, Value>* database = nullptr;

		Up_Base(DataBase<Key, Value>* db) : database{ db } {
			std::cout << "Up_Base Create\n";			
		}		

		void check(Base_Mixin* mixin) override {
			std::cout << "--Check_Derivaive\n";
			mixin->compare();
		}		

	};

	Base* data = nullptr;
	
	template <typename Key, typename Value> bool add_data(Key key, Value value) {
				
		struct Wrapper : public Mixin<Wrapper> {
			using DataBase_Type1 = Up_Base<Key, Value>;
			void set_type_compare() {				
				std::cout << "Compare\n";
			}
		};

		data->check(new Wrapper);

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