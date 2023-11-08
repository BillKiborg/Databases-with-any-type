#pragma once
#include <memory>
#include "Abstract_DataBase.h"

//class User {
//private:
//
//	std::unique_ptr<Abstract_DataBase> dataBase;
//
//public:
//
//	template <typename Key, typename Value> void set_database(Template_DataBase<Key, Value>* new_database) {
//		
//		if (!dataBase) {
//			std::cout << "Новая база данных: " << typeid(*new_database).name() << "\n\n";
//			dataBase
//				= std::move(std::unique_ptr<Abstract_DataBase>(
//					dynamic_cast<Abstract_DataBase*>(new_database))
//				);
//		}
//		else {
//			std::cout << "База данных уже существует\n";
//		}
//		
//	}
//
//	void run() {
//		dataBase->add_data("Key", "Value");		
//	}
//
//};