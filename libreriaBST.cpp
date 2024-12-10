#include <iostream>
#include "libreriaBST.h"

using namespace std;

Node::Node(int j)
    : data{j},left_child{nullptr},right_child{nullptr}{};

Node* Node::insertR(int j) {
    Node* r = this;
    if (r == NULL) {
        return new Node(j);
    }
    if (r->data == j) {
        return r;
    }
    if (data < r->data) {
        r->left_child = r->left_child->insertR(j);
    }
    else if (data > r->data) {
        r->right_child = r->right_child->insertR(j);
    }
    
    return r;
}

Node* Node::insertI(int j) {
    Node* r = this;
    Node* current = r;
    Node* father{NULL};
    bool left;
    while (r != NULL){
        if (r->data == j) {
            return current;
        }
        if (j < r->data) {
            father = r;
            r = r->left_child;
            left = true;
        } else if (j > r->data) {
            father = r;
            r = r->right_child;
            left = false;
        }
    }
    if (left) {
        father->left_child = new Node(j);
    } else if (!left) {
        father->right_child = new Node(j);
    }

    return current;
}

bool Node::searchI (int j) {
    Node* r = this;
    if (r ==  NULL) {
        return false;
    }
    bool check = false;
    if (r->data == j){
        check = true;
    } else if (r->data > j){
        r = r->left_child;
    } else {
        r = r->right_child;
    }

    while (!check && r!=NULL) {
        if (r->data == j) {
            check = true;
        } else if (r->data > j){
            r = r->left_child;
        } else {
            r = r->right_child;
        }
    }

    return check;
}

bool Node::searchR (int j){
    if (this == NULL) {
        return false;
    }
    if (this->data == j){
        return true;
    }
    if (j < this->data) {
        return this->left_child != NULL && this->left_child->searchR(j);
    } else {
        return this->right_child != NULL && this->right_child->searchR(j);
    }
}

void Node::inOrder() {
    Node* r=this;
    if (r == NULL) return;
    
    r->left_child->inOrder();
    cout << r->data << " ";
    r->right_child->inOrder();
}

ostream& operator<<(ostream& os, Node* N) {
    os << N->data;
    return os;
}

istream& operator>>(istream& is, Node* N) {
    is >> N->data;
    N->lchild = nullptr;
    N->rchild = nullptr;
    return is;
}
