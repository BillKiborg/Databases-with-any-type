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

	struct Comparator {
		virtual ~Comparator() = default;
	};

	template <typename Type> struct Type_Comparator : public Comparator {
		using Save_Type = Type;
		Type_Comparator(Type) {}
		Save_Type get_type() {
			return Save_Type{};
		}
	};
		
	struct Base {
		virtual ~Base() = default;	
		virtual void check(Comparator*) = 0;
		template <typename Type> Type* get_Type() {
			//check();
		}
	};	

	template <typename Comp> struct Mixin : public Base {
		void check(Comparator* comp) override {
			static_cast<Comp>(comp)->get_type();
		}
	};
	
	template <typename Key, typename Value>	struct Up_Base : public Base {		
		
		using TypeKey	= Key;
		using TypeValue = Value;
		using DataType = Up_Base<Key, Value>;

		TypeKey get_type_key() {
			return TypeKey{};
		}

		TypeValue get_type_value() {
			return TypeValue{};
		}

		DataBase<Key, Value>* database = nullptr;

		Up_Base() = default;
		Up_Base(DataBase<Key, Value>* db) : database{ db } {
			std::cout << "Up_Base Create\n";			
		}	

		template <typename Data> void casting(Base* base) {
			std::cout << "Casting\n";
		}

		void check(Comparator* base) override {
			
		}

	};

	Base* data = nullptr;


	
	template <typename Key, typename Value> bool add_data(Key key, Value value) {
				
		using DataType = Up_Base<Key, Value>;	
		

		//data->check();
		
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