#pragma once

//Abstract_DataBase::~Abstract_DataBase() = default;
//
//template <typename Key, typename Value> void Abstract_DataBase::set_database(Template_DataBase<Key, Value>* _database) {
//
//	std::cout << "+++\n";
//
//
//
//}
//
//template <typename Key, typename Value> bool Abstract_DataBase::add_data(Key key, Value value) {
//
//	using Key_Type = convertible_selector<Key, std::string, double>::Type;
//	using Value_Type = convertible_selector<Value, std::string, double>::Type;
//
//	std::cout << "General\n";
//	std::cout << "Key Type: " << typeid(Key_Type).name() << "\n";
//	std::cout << "Value Type: " << typeid(Value_Type).name() << "\n";
//
//	std::cout << "DataBase: " << typeid(database).name() << "\n";
//
//	if (auto db = dynamic_cast<Template_DataBase<std::string, std::string>*>(database)) {
//		std::cout << "База работает\n";
//	}
//	else {
//		std::cout << "Не работает\n";
//	}
//
//	
//
//	/*if constexpr (std::is_convertible<Key, std::string>::value && std::is_convertible<Value, std::string>::value) {
//		return add_data(std::string{ key }, std::string{ value });
//	}
//
//	if constexpr (std::is_convertible<Key, double>::value && std::is_convertible<Value, double>::value) {
//		return add_data((double)(key), double(value));
//	}*/
//
//	return false;
//}

//template <> bool Abstract_DataBase::add_data(double key, double value) {
//
//	/*std::cout << "Spec String\n";
//	for (auto& base : database) {
//
//		std::cout << "Base: " << typeid(*base).name() << "\n";
//		if (auto database = dynamic_cast<Template_DataBase<double, double>*>(base)) {
//			std::cout << "Попал\n";
//			return database->_add_data(key, value);
//		}
//	}*/
//
//	return false;
//}
//
//template <> bool Abstract_DataBase::add_data(std::string key, std::string value) {
//
//	/*std::cout << "Spec String\n";
//	for (auto& base : database) {
//
//		std::cout << "Base: " << typeid(*base).name() << "\n";
//		if (auto database = dynamic_cast<Template_DataBase<std::string, std::string>*>(base)) {
//			std::cout << "Попал\n";
//			return database->_add_data(key, value);
//		}
//	}*/
//
//	return false;
//}