#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* lchild, * rchild;

    Node(int n) {
        data = n;
        lchild = nullptr;
        rchild = nullptr;
    }
};

Node* addLeaf_R(Node* r, int data) {
    if (r == NULL) {
        return new Node(data);
    }
    if (r->data == data) {
        return r;
    }
    if (data < r->data) {
        r->lchild = addLeaf_R(r->lchild, data);
    }
    else if (data > r->data) {
        r->rchild = addLeaf_R(r->rchild, data);
    }
    
    return r;
}

Node* addLeaf_L(Node* r, int data) {
    Node* current = r;
    Node* father{nullptr};
    bool left;
    while (r != nullptr) {
        if (r->data == data) {
            return current;
        }
        if (data < r->data) {
            father = r;
            r = r->lchild;
            left = true;
        }
        else if (data > r->data) {
            father = r;
            r = r->rchild;
            left = false;
        }
    }
    if (left) {
        father->lchild = new Node(data);
    }
    else if (!left) {
        father->rchild = new Node(data);
    }
    
    return current;
}

bool search(Node* r, int data) {
    bool check;
    if (r == NULL) {
        check = false;
        return check;
    }
    if (r->data == data) {
        check = true;
        return check;
    }
    if (data < r->data) {
        check = search(r->lchild, data);
    }
    else if (data > r->data) {
        check = search(r->rchild, data);
    }
    
    return check;
}

void preOrder(Node* r) {
    if (r == NULL) return;

    cout << r->data << " ";
    preOrder(r->lchild);
    preOrder(r->rchild);
}

void inOrder(Node* r) {
    if (r == NULL) return;
    
    inOrder(r->lchild);
    cout << r->data << " ";
    inOrder(r->rchild);
}

void postOrder(Node* r) {
    if (r == NULL) return;

    postOrder(r->lchild);
    postOrder(r->rchild);
    cout << r->data << " ";
}

int altezza(Node* r) {
    if (r == NULL) return 0;

    int l = altezza(r->lchild);
    int r2 = altezza(r->rchild);
    int max{0};

    if(l >= r2) {
        l = max;
    } else {
        r2 = max;
    }

    return max+1;
}

Node* remove(Node* r, int data) {                
    if (r == NULL) {
        return r;
    }
    
    if (r->data = data){
        if (r->lchild == nullptr & r->rchild == nullptr) {
            r = nullptr;
            delete r;
            return r;
        } else if(r->lchild == nullptr) {
            r = r->rchild;
            r->rchild = nullptr;
            delete r;
            return r;
        } else if(r->rchild == nullptr) {
            r = r->lchild;
            r->lchild = nullptr;
            delete r;
            return r;
        }
    } else if (data < r->data) {
        r = remove(r->lchild, data);
    } else if (data > r->data) {
        r = remove(r->rchild, data);
    }
}

bool f_bst(Node* r) {                               
    bool bst {true};
    if (r->lchild->data > r->data && r->rchild->data < r->data) {
        return false;
    } else if (r->lchild == nullptr && r->rchild == nullptr) {
        return true;
    } else if (r->lchild->data < r->data && r->rchild->data > r->data){
        bst = f_bst(r->lchild);
        bst = f_bst(r->rchild);
    }
    
    return bst;
}