#pragma once
#include "Template_DataBase.h"

//template<typename A, typename B, typename C> struct convertible_selector {
//	using Type
//		= std::conditional_t<std::is_convertible<A, B>::value, B,
//		std::conditional_t<std::is_convertible<A, C>::value, C, A>>;
//};
//
//class Abstract_DataBase {
//private:
//	Abstract_DataBase* database = nullptr;	
//
//public:
//	virtual ~Abstract_DataBase() = 0;
//	template <typename Key, typename Value> bool add_data(Key, Value);
//	template <typename Key, typename Value> void set_database(Template_DataBase<Key, Value>*);
//
//};

#include "Abstract_DataBase.hpp"