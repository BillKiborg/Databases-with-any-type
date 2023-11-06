#include <iostream>
#include <any>
//#include <vld.h>
#include "Templ.h"
#include <vector>



int main() {
	setlocale(LC_ALL, "rus");		

	User user;
	user.set_database(new String_DataBase);
	user.use();

	return 0;
}