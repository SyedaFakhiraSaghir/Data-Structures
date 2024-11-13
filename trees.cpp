#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    int val;
    Node* r;
    Node* l;
    Node* next;
    Node() {
        val = 0;
        r = NULL;
        l = NULL;
        next = NULL;
    }
    Node(int x) {
        val = x;
        r = NULL;
        l = NULL;
        next = NULL;
    }
};

class tree {
public:
    Node* root;
    int minv = -999;
    int maxv = 999;
    tree() {
        root = NULL;
    }

    void insert(int ne) {
        Node* n = new Node(ne);
        queue<Node*> q;
        if (root == NULL) {
            root = n;
        }
        else {
            q.push(root);
            while (!q.empty()) {
                Node* temp = q.front();
                q.pop();
                if (temp->l != NULL) {
                    q.push(temp->l);
                }
                else {
                    temp->l = n;
                    return;
                }
                if (temp->r != NULL) {
                    q.push(temp->r);
                }
                else {
                    temp->r = n;
                    return;
                }
            }
        }

    }

    int H(Node* head) {
        if (head == NULL) {
            return -1;
        }
        else {
            return max(H(head->l), H(head->r)) + 1;
        }
    }

    void display(Node* t) {
        if (t == NULL) {
            return;
        }
        cout << t->val << " ";
        display(t->l);
        display(t->r);
    }

    bool fullbt(Node* n) {
        if (n == NULL) {
            return true;
        }
        if (n->l == NULL && n->r == NULL) {
            return true;
        }

        if (n->l && n->r) {
            return fullbt(n->l) && fullbt(n->r);
        }
        return false;
    }

    bool perfectbt(Node* n, int d, int height) {
        if (n == NULL) {
            return true;
        }
        if (n->l == NULL && n->r == NULL) {
            return (d == height);
        }
        else {
            return perfectbt(n->r, d + 1, height) && perfectbt(n->l, d + 1, height);
        }
    }

    bool completebt(Node* n, int i, int t) {
        if (n == NULL) {
            return true;
        }
        if (i >= t) {
            return false;
        }
        return completebt(n->l, 2 * i + 1, t) && completebt(n->r, 2 * i + 2, t);
    }

    int numberofnodes(Node* n) {
        if (n == NULL) {
            return 0;
        }

        return 1 + numberofnodes(n->l) + numberofnodes(n->r);
    }

    bool bst(Node* n, int min, int max) {
        if (n == NULL) {
            return true;
        }
        if (n->val <= min || n->val >= max) {
            return false;
        }
        return bst(n->l, min, n->val) && bst(n->r, n->val, max);
    }
};

int main() {
    tree t;
    int num, x;
    cout << "\nInsert the number of nodes in the tree: ";
    cin >> num;

    for (int i = 0; i < num; i++) {
        cout << "NUM : ";
        cin >> x;
        t.insert(x);
    }

    t.display(t.root);
    cout << endl;

    if (t.perfectbt(t.root, 0, t.H(t.root))) {
        cout << "It is a perfect binary tree\n";
    }
    else {
        cout << "It is NOT a perfect binary tree\n";
    }

    if (t.fullbt(t.root)) {
        cout << "It is a full binary tree\n";
    }
    else {
        cout << "It is NOT a full binary tree\n";
    }

    if (t.completebt(t.root, 0, t.numberofnodes(t.root))) {
        cout << "It is a complete binary tree\n";
    }
    else {
        cout << "It is NOT a complete binary tree\n";
    }

    if (t.bst(t.root, t.minv, t.maxv)) {
        cout << "It is a binary search tree\n";
    }
    else {
        cout << "It is NOT a binary search tree\n";
    }

    return 0;
}
