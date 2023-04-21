// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "hashtableclosed.h"
#include <iostream>

HashTableClosed::HashTableClosed() {
	count = 0;
	mem_size = 8;
	array = new Pair[mem_size];
}

HashTableClosed::~HashTableClosed() {
	delete[] array;
}

int HashTableClosed::hash_func(std::string p_name, int offset) {
	int sum = 0;
	for (int i = 0; i < p_name.length(); i++)
		sum += p_name[i];
	return (sum % mem_size + offset * offset) % mem_size;
}

void HashTableClosed::add(std::string l_name, std::string p_name) {
	int index = -1, i = 0;
	for (; i < mem_size; i++) {
		index = hash_func(p_name, i);
		if (array[index].status == enPairStatus::free || array[index].status == enPairStatus::deleted)
			break;
	}
	if (i >= mem_size) {
		resize();
		add(l_name, p_name);
	}
	else {
		array[index] = Pair(l_name, p_name);
		count++;
	}
}

void HashTableClosed::resize() {
	Pair* save = array;
	int save_ms = mem_size;
	mem_size *= 2;
	array = new Pair[mem_size];
	count = 0;
	for (int i = 0; i < save_ms; i++) {
		Pair& old_pair = save[i];
		if (old_pair.status == enPairStatus::engaged)
			add(old_pair.login_name, old_pair.pass_name);
	}
	delete[] save;
}

//void HashTableClosed::find(std::string p_name) {
//	for (int i = 0; i < mem_size; i++) {
//		int index = hash_func(p_name, i);
//		//std::cout << "\nindex hash_func(): " << index << std::endl;
//		if (array[index].status == enPairStatus::engaged) {
//			std::cout << array[index].pass_name;
//		}
//		//else if (array[index].status == enPairStatus::free)
//		//	return "";
//	}
//	//return "";
//}

void HashTableClosed::del(std::string p_name) {
	int index = -1;
	for (int i = 0; i < mem_size; i++) {
		index = hash_func(p_name, i);
		if (array[index].status == enPairStatus::engaged && (array[index].pass_name != p_name)) {
			array[index].status = enPairStatus::deleted;
			count--;
			return;
		}
		else if (array[index].status == enPairStatus::free)
			return;
	}
}

HashTableClosed::Pair HashTableClosed::getPair(std::string str) {
	for (int i = 0; i < mem_size; i++) {
		if (array[i].pass_name == str) {
			return array[i];
		}
	}
}

void HashTableClosed::printHashTableClosed() {
	for (int i = 0; i < mem_size; i++) {
		if (array[i].pass_name != "")
			std::cout << array[i].login_name << " " << array[i].pass_name << std::endl;
	}
	std::cout << std::endl;
}
