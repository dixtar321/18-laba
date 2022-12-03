#include "Header.h"
#include <iostream>
#include <map>

using namespace std;

tree::Node::Node(const string& name) {
    this->name = name;
}

tree::tree() {
    root = NULL;
}

bool tree::AddRoot(const string& rootName) {
    if (root == NULL) {
        root = new Node(rootName);
        arr[rootName] = root->childs;
        return 1;
    }
    else {
        cout << "ERROR!!!!!!!" << endl;
        return 0;
    }
}


void tree::AddNode(const string& parent, const string& child) {
    if (root != NULL) {
        Node* son = new Node(child);
        arr[child] = son->childs;
        arr[parent].push_back(son);
    }
    else
        cout << "Error. Firstly create the root" << endl;
}

int recurs_level = -1;
void tree::tree_print(const string& NodeName) { // 
    vector<Node*> cur = arr[NodeName];
    vector<Node> buff;
    recurs_level++;
    for (int t = 0; t < recurs_level; t++)
        cout << "   ";
    cout << NodeName << ":" << endl;
    for (int i = 0; i < cur.size(); i++) {
        tree_print(cur[i]->name);
        recurs_level--;

    }
}

//void tree::tree_print(const string& NodeName) {
//    vector<Node*> cur = arr[NodeName];
//    vector<Node*> buff;
//    cout << NodeName << ":" << endl;
//    for (int i = 0; i < cur.size(); i++) {
//        cout << "   " << cur[i]->name << endl;
//        buff.push_back(cur[i]);
//    }
//    for (int i = 0; i < buff.size(); i++) {
//        tree_print(buff[i]->name);
//    }
//}

ostream& operator <<(ostream& out, tree& Tree) {
    Tree.tree_print(Tree.root->name);
    return out;
}

tree::~tree() {
    for (int i = 0; i < root->childs.size(); i++) {
        delete root->childs[i];
    }
    delete root;
}