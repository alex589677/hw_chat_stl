#pragma once
#include <iostream>
#include <map>
#include "User.h"
#include "hashtableclosed.h"

using std::cout;
using std::endl;

std::map<int, User> users;
static HashTableClosed ht;			// hash table how save login and password

User Handler1() {
	bool isExit = true;
	char myChoice;
	int counterUsers = 0;
	while (isExit) {
		cout << "\nMenu1:"
			 << "\n1-Registrations Users"
			 << "\n2-Create message by login"
			 << "\n4-ShowAllUsers"
			 << "\n5-Show HashTable array"
			 << "\n6-exit\n";
		std::cin >> myChoice;
		switch (myChoice) {
			case '6': {			// quick exit
				isExit = false;
				User user;
				return user;
				//break;
			}
			case '1': {
				// registration user
				// and save login and password in hash table
				cout << "Create you login: \n";
				std::string myLogin;
				std::cin >> myLogin;
				cout << "Create you password: \n";
				std::string myPassword;
				std::cin >> myPassword;
				cout << "Enter your name: \n";
				std::string myName;
				std::cin >> myName;

				ht.add(myLogin, myPassword);			// added password to hash table

				User user(myLogin, myPassword, myName);
				users.insert({ counterUsers++, user });
				user.show();
				break;
			}
			case '2': {
				cout << "Input index user(0): \n";
				int index = 0;
				std::cin >> index;
				static User currentUser = users[index++];
				cout << "new current user selected " << currentUser;
				cout << "\nAuthorization user \n";
				cout << "Input your login: \n";
				std::string login;
				std::cin >> login;
				cout << "Input your password: \n";
				std::string password;
				std::cin >> password;
				if (login == currentUser.getUserLogin() && password == currentUser.getUserPassword()) {
					cout << "well done" << endl;
					return currentUser;
				}
				else {
					cout << "Wrong login or Password!!!\nTry input data for authorizatioan...";
				}
				break;
			}
			case '4': {
				// map<int, User>::iterator it == auto
				for (auto it = users.begin(); it != users.end(); it++) {
					cout << "id: " << it->first
						<< " login: " << it->second.getUserLogin()
						<< " password: " << it->second.getUserPassword()
						<< " name: " << it->second.getUserName() 
						<< "\n------------\n";
				}
				break;
			}
			case '5': {
				cout << "Hash Table: \n";
				ht.printHashTableClosed();
				break;
			}
		}
	}
	return User();
}