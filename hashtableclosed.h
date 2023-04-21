#pragma once
#include <string>
#include <fstream>
//#define NAMELENGTH 10 // ����������� ����� �����
//typedef char login[NAMELENGTH]; // ��� ��� ��������

class HashTableClosed {
public:
	enum class enPairStatus {
		free, engaged, deleted
	};
	struct Pair {
		Pair() : login_name(""), pass_name(""), status(enPairStatus::free) {}		// ����������� �� ���������
		// ����������� �����������
		Pair(std::string l_name, std::string p_name) : status(enPairStatus::engaged), login_name(l_name), pass_name(p_name) {}
		
		Pair& operator=(const Pair& other) {
			// �������� ������������
			login_name = other.login_name;
			pass_name = other.pass_name;
			status = other.status;
			return *this;
		}
		std::string login_name;
		std::string pass_name; //�(����)
		enPairStatus status;	// ��������� ������
	};
	Pair* array;
	int mem_size;
	int count;
	void resize();
	int hash_func(std::string p_name, int offset);
	HashTableClosed();
	~HashTableClosed();
	void add(std::string l_name, std::string p_name);
	//void find(std::string p_name);			
	void del(std::string p_name);
	HashTableClosed::Pair getPair(std::string str);		// cout << ht.pass_name ��� cout << ht.login_name 
	void printHashTableClosed();
};
