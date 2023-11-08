#pragma once
#include <iostream> 
#include <type_traits>
#include <vector>
#include <algorithm>
#include <map>

#include "Abstract_DataBase.h"

class String_DataBase : public Template_DataBase<std::string, std::string>, public Abstract_DataBase {
private:

	std::map<std::string, std::string> map;

public:
	bool _add_data(std::string key, std::string value) override {

		std::cout << "_add\n";
		map.insert(std::make_pair(key, value));
		return true;
	}

};