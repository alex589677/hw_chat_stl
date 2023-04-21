#pragma once
#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include "TrieAutocomplete.h"

using std::cout;
using std::endl;

void callHandleFunction() {
	//----autocomplete----
	std::string s[] = { "adas", "adf", "am", "aok", "dk", "dae", "dad" };
	int length_string = sizeof(s) / sizeof(s[0]);
	Trie* trie = new Trie();
	// input strings in trie tree
	for (int i = 0; i < length_string; i++) {
		trie->insert(s[i]);
	}
	//----autocomplete----
	User currentUser = Handler1();		// call handler file Utilites.h
	std::multimap<string, string> containers;		// container for included messages local
	std::multimap<string, string> allContainers;
	cout << currentUser << endl;
	int counter = 0;
	bool isFlag = true;
	// exit out on menu 1 if (message == "")!
	if (currentUser.getUserName() == "")
		isFlag = false;
	while (isFlag) {
		cout << "Menu2: \n"
			<< "1-write text to user\n"
			<< "2-go previous menu\n"
			<< "3-show local chat\n"
			<< "4-show all chat\n"
			<< "5-exit\n";
		std::cin >> counter;
		if (counter == 5) {
			isFlag = false;
			break;
		}
		if (counter == 1) {
			// write message
			cout << "Input login from write message: \n";
			std::string loginSource = "";
			std::cin >> loginSource;
			cout << "Input login to write message: \n";
			std::string loginTarget = "";
			std::cin >> loginTarget;
			std::string flag = "";
			cout << "Input word for 'local' or 'all' create message: \n";
			std::cin >> flag;
			trie->printTrie();				// hash-table off!!!
			cout << "Write your message and input '@' to end you message, and click Enter: \n";
			std::string str1;
			// input message and using autocomplete
			std::getline(std::cin, str1, '@');		// after input prefix no read data tree*/
			//cin >> str1;

			// print prefix words in trie
			if (str1.length() == 1)
				trie->printTrieWithPrefix(str1);  // hash-table off!!!

			Message message1(loginSource, loginTarget, str1);
			if (flag == "local") {
				cout << "[" << loginTarget << "]: " << message1.getText() << endl;
				containers.insert(make_pair(loginTarget, message1.getText()));
			}
			else if (flag == "all") {
				cout << "[" << loginTarget << "]: " << message1.getText() << endl;
				allContainers.insert(make_pair(loginTarget, message1.getText()));
			}
		}
		if (counter == 2) {
			// go to previous menu
			Handler1();
		}
		if (counter == 3) {
			// show local chat
			cout << "--------LocalChat------------" << endl;
			for (auto& item : containers) {
				cout << "login: " << item.first
					<< "\nmessage: " << item.second << endl;
			}
			cout << "--------------" << endl;
		}
		if (counter == 4) {
			// show for all chat
			cout << "--------AllChat------------" << endl;
			for (auto& item : allContainers) {
				cout << "login: " << item.first
					<< "\nmessage: " << item.second << endl;
			}
			cout << "--------------" << endl;
		}
	}
}