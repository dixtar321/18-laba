#pragma once
#include <map>
#include <vector>
#include <iostream>
using namespace std;

class tree {

private:
    class Node {
    public:
        string name;
        vector<Node*> childs;
        Node(const string& name);
    };
    Node* root;
    map<string, vector<Node*>> arr;
    void tree_print(const string& NodeName);

public:
    tree();
    bool AddRoot(const string& rootName);
    void AddNode(const string& parent, const string& child);
    friend ostream& operator <<(ostream& out, tree& Tree);
    ~tree();
};