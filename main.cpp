// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
// author А.С. Гадиатулин group CPLUS-1006 block Algorithms of C++ module STL
#include <iostream>
#include "Utilites.h"
#include "Message.h"
#include "HandleGeneral.h"

/**
*	call handler file HandleGeneral.h after Utilites.h and then continue HandleGeneral.h
*/

int main() {
	setlocale(LC_ALL, "Russian");

	callHandleFunction();

	std::cout << "Game over" << std::endl;

	return 0;
}