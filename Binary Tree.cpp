# include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* r;
		Node* l;
		Node(int data):data(data), r(nullptr), l(nullptr){
		}
};

class BST{
	Node* root;
	public:
		BST(){
			root = nullptr;
		}
		
		void insert(int data)
		{
			Node* new_node = new Node(data);
			if(!root){
				root = new_node;
			}
			
			else{
				Node* curr = root;
				Node* prev = curr;
				while(curr){
					prev = curr;
					if(data > curr->data){
						curr = curr->r;
					}
					else{
						curr = curr->l;
					}
				}

				if(data <= prev->data){
					prev->l = new_node;
				}
				else{
					prev->r = new_node;
				}
			}
		}
		
		void InOrder(Node* curr){
			if(!curr){
				return;
			}
			InOrder(curr->l);
			cout << curr->data << " ";
			InOrder(curr->r);
		}
		
		void Display(){
			InOrder(root);
		}
		
		Node* Deletei(Node* curr, int data){
			// Searching
			// Base Case: Search End
			if(curr == nullptr){
				return curr;
			}
			
			// Right Traversal
			if(data > curr->data){
				curr->r = Deletei(curr->r, data);
			}
			// Left Traversal
			else if(data < curr->data){
				curr->l = Deletei(curr->l, data);
			}
			
			// Found: Deletion
			else{
				// Only Left or No Child
				if(curr->l ==  nullptr){
					Node* temp = curr->r;
					delete curr;
					return temp;
				}
				// Only Right
				else if(curr->r == nullptr){
					Node* temp = curr->l;
					delete curr;
					return temp;
				}
				
				// Both Children
				Node* temp = FindPred(curr->r);
				curr->data = temp->data;
				curr->r = Deletei(curr->r, temp->data);
			}
			return curr;
		}
		
		void Delete(int data){
			root = Deletei(root, data);
		}
		
		Node* FindPred(Node* curr){
			while(curr->l != nullptr){
				curr = curr->l;	
			}
			return curr;
		}
		
		Node* FindSucc(Node* curr){
			while(curr->r != nullptr){
				curr = curr->r;	
			}
			return curr;
		}
		
		int FindHeight(Node* curr){
			if(curr == nullptr){
				return -1;
			}
			
			int ltree = FindHeight(root->l);
			int rtree = FindHeight(root->r);
			
			return max(ltree, rtree) + 1;
		}
		
		int FindDepth(Node* curr){
			if(curr == nullptr || root == nullptr){
				return 0;
			}
			if(curr == root){
				return 0;
			}
			else if(curr->data <= root->data){
				return 	FindHeight(curr->l);;
			}
			else{
				return FindHeight(curr->r);	
			}
		}
};

int main(){
	BST x;
	x.insert(5);
	x.insert(10);
	x.insert(4);
	x.insert(16);
	x.insert(1);
	x.insert(9);
	x.insert(41);
	x.insert(15);
	
	cout << "BST: ";
	x.Display();
	
	x.Delete(15);
	
	cout << endl;
	cout << "BST: ";
	x.Display();
	
	return 0;
}
