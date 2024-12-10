#ifndef LIBRERIABST_H
#define LIBRERIABST_H
#include<iostream>

using namespace std;

class Node{
    private:
    int data;
    Node* right_child;
    Node* left_child;

    public:
    Node(int j);
    Node* insertR(int j);
    Node* insertI(int j);
    bool searchI(int j);
    bool searchR(int j);
    void inOrder();
    friend ostream& operator<<(ostream& os, Node* N);
    friend istream& operator>>(istream& is, Node* N);
    void preOrder();
    void postOrder();
    bool isBst();
    Node* deleteNode(int j);
};

#endif
