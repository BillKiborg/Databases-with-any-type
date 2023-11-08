#pragma once

template <typename Key, typename Value> class Template_DataBase {
public:
	virtual ~Template_DataBase() = default;
	virtual bool _add_data(Key, Value) = 0;
};