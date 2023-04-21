#pragma once

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

// Trie nodeinfo
class TrieNode {

public:
    char data_;
    TrieNode* children_[26];
    bool isEndingChar_;

    TrieNode(char data = '/') : data_(data), isEndingChar_(false) {         // constructor
        memset(children_, 0, sizeof(TrieNode*) * 26);
    };
};

class Trie {
public:
    Trie() {
        root_ = new TrieNode();
    }
    ~Trie() {
        destory(root_);
    }

    void insert(string inputText);
    bool find(string searchText);
    void destory(TrieNode* p);
    void printTrie();
    void dfs_traverse(TrieNode* p, string buf, vector<string>& tmp_str);
    void printTrieWithPrefix(string start);

private:
    TrieNode* root_;
};
