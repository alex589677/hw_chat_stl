#include "TrieAutocomplete.h"
#include <iostream>

using std::cout;
using std::endl;

void Trie::insert(string inputText) {
    if (inputText.size() <= 0) {
        return;
    }

    TrieNode* tmp = root_;
    int i;

    // Traverse every character in des
    for (i = 0; i < inputText.size(); i++) {
        // The des[i] insert position at trie tree.
        int index = inputText[i] - 'a';
        if (tmp->children_[index] == nullptr) {
            TrieNode* newNode = new TrieNode(inputText[i]);
            tmp->children_[index] = newNode;
        }
        tmp = tmp->children_[index];
    }

    tmp->isEndingChar_ = true;
}

// Delete the TrieNode, and release the space
void Trie::destory(TrieNode* p) {
    if (p == nullptr) {
        return;
    }

    for (int i = 0; i < 26; i++) {
        destory(p->children_[i]);
    }

    delete p;
    p = nullptr;
}

// Judge if a string is match with Trie tree
bool Trie::find(string searchText) {
    if (searchText.size() == 0) {
        return false;
    }

    TrieNode* tmp = root_;
    int i;

    for (i = 0; i < searchText.size(); i++) {
        // The index of the current char's position
        int index = searchText[i] - 'a';
        if (tmp->children_[index] == nullptr) {
            return false;
        }

        // Move the tmp to the next line
        tmp = tmp->children_[index];
    }

    // End position to ensure wether the input str is match.
    if (tmp->isEndingChar_ == false) {
        return false;
    }

    return true;
}

// Traverse the trie tree recursion
// para1: TrieNode
// Para2: prefix string
// para3: result vector
void Trie::dfs_traverse(TrieNode* p, string buf, vector<string>& tmp_str) {
    if (p == nullptr) {
        return;
    }

    // if match, just and the result to vector
    if (p->isEndingChar_ == true) {
        tmp_str.push_back(buf);
    }

    for (int i = 0; i < 26; i++) {
        if (p->children_[i] != nullptr) {
            // Just add the prefix every time
            dfs_traverse(p->children_[i],
                buf + (p->children_[i]->data_), tmp_str);
        }
    }
}

// Print the all trie tree string with dictionary order
void Trie::printTrie() {
    vector<string> tmp_str;
    int i, j;

    for (i = 0; i < 26; i++) {
        string buff = "";
        if (root_->children_[i] != nullptr) {
            // Will be called recursion.
            // Input with TrieNode, the prefix character and the result vector
            dfs_traverse(root_->children_[i],
                buff + root_->children_[i]->data_, tmp_str);
        }
    }

    cout << "Trie string: " << tmp_str.size() << endl;
    for (j = 0; j < tmp_str.size(); j++) {
        cout << tmp_str[j] << " ";
    }
    cout << endl;
}

// Input the prefix, and search the prefix related string
void Trie::printTrieWithPrefix(string start) {
    vector<string> tmp_str;
    int i, j;
    TrieNode* tmp = root_;

    // Ensure prefix is exist
    for (int i = 0; i < start.size(); i++) {
        int index = start[i] - 'a';
        if (tmp->children_[index] == nullptr) {
            cout << "No prefix with " << start << endl;
            return;
        }
        tmp = tmp->children_[index];
    }

    // Prefix is a matched string
    tmp_str.push_back(start);

    for (i = 0; i < 26; i++) {
        string buff = start;
        if (tmp->children_[i] != nullptr) {
            // Will be called recursion
            dfs_traverse(tmp->children_[i], buff + tmp->children_[i]->data_, tmp_str);
        }
    }

    cout << "Trie string: " << tmp_str.size() << endl;
    for (j = 0; j < tmp_str.size(); j++) {
        cout << tmp_str[j] << endl;
    }
}

