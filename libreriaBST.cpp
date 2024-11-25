#include <iostream>
#include "libreriaBST.h"

using namespace std;

Node::Node(int j)
    : data{j},left_child{nullptr},right_child{nullptr}{};

Node* Node::insertR(int j) {
    Node* r=this;
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

void Node::inOrder() {
    Node* r=this;
    if (r == NULL) return;
    
    r->left_child->inOrder();
    cout << r->data << " ";
    r->right_child->inOrder();
}