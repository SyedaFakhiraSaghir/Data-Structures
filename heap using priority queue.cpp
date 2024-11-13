#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    node* parent;
    int data;
    node* right;
    node* left;
    node* next;

    node() {
        data = 0;
        next = NULL;
        parent = NULL;
        right = NULL;
        left = NULL;
    }

    node(int d) {
        next = NULL;
        data = d;
        parent = NULL;
        right = NULL;
        left = NULL;
    }
};

class binarySearch {
public:
    node* head;
    node* lastNode;
    binarySearch() {
        head = NULL;
    }

    void insertionMax(int v) {
        queue<node*> q;
        node* newnode = new node(v);

        if (head == NULL) {
            head = newnode;
        } else {
            q.push(head);
            while (1) {
                node* n = q.front();
                if (n->left == NULL) {
                    n->left = newnode;
                    newnode->parent = n;
                    break;
                } else {
                    q.push(n->left);
                }
                if (n->right == NULL) {
                    n->right = newnode;
                    newnode->parent = n;
                    break;
                } else {
                    q.push(n->right);
                }
                q.pop();
            }

            while (!q.empty()) {
                q.pop();
            }
            heapifymax(newnode);
        }
    }

    void heapifymin(node* n) {
        while (n->parent != NULL && n->parent->data > n->data) {
            swap(n->data, n->parent->data);
            n = n->parent;
        }
    }

    void heapifymax(node* n) {
        while (n->parent != NULL && n->parent->data < n->data) {
            swap(n->data, n->parent->data);
            n = n->parent;
        }
    }

    void deleteroot(node*& root, node*& ln) {
        if (root == NULL) {
            return;
        }
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        } else {
            swap(root->data, ln->data);
            node* p = ln->parent;
            if (p->left == ln) {
                p->left = NULL;
            } else {
                p->right = NULL;
            }
            delete ln;
            ln = NULL;
        }
    }

    node* findLastNode(node* root) {
        if (root == NULL) {
            return NULL;
        }

        queue<node*> q;
        q.push(root);

        while (!q.empty()) {
            node* current = q.front();
            q.pop();
            if (current->left) {
                q.push(current->left);
            }
            if (current->right) {
                q.push(current->right);
            }
            if (q.empty()) {
                return current;
            }
        }

        return NULL;
    }

    // inorder traversal
    void traverse(node* n) {
        if (n == NULL) {
            return;
        }
        cout << n->data << " ";
        traverse(n->left);
        traverse(n->right);
    }
};

int main() {
    binarySearch b;
    b.insertionMax(35);
    b.insertionMax(33);
    b.insertionMax(42);
    b.insertionMax(10);
    b.insertionMax(14);
    b.insertionMax(19);
    b.insertionMax(27);
    b.insertionMax(44);
    b.insertionMax(26);
    b.insertionMax(31);

    cout << "Min: ";
    b.traverse(b.head);
    cout << endl;
    node* lastNode = b.findLastNode(b.head);
    cout << "Last node: " << lastNode->data << endl;
    b.deleteroot(b.head, lastNode);
    b.heapifymin(b.head);
    cout << "Max: ";
    b.traverse(b.head);

    return 0;
}
