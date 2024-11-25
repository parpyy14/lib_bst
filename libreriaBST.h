#ifndef LIBRERIABST_H
#define LIBRERIABST_H

class Node{
    private:
    int data;
    Node* right_child;
    Node* left_child;

    public:
    Node(int j);
    Node* insertR(int j);
    void inOrder();
};

#endif

