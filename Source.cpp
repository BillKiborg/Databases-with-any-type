#include <iostream>
#include "Templ.h"
#include <any>


int main() {
	setlocale(LC_ALL, "rus");

	User user;
	user.set_database(new String_DataBase);
	user.use();

	return 0;
}