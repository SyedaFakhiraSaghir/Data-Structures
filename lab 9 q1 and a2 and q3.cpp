#include<iostream>
using namespace std;

class Node{
	public:
		int val;
		Node *r;
		Node *l;
		int height;
		Node()
		{
		}
		Node(int x)
		{
			val=x;
			r=NULL;
			l=NULL;
			height=0;
		}
};

class tree{
	public:
	int balance(Node *n)
	{
//			int b=H(root->l)-H(root->r);
		if(n==NULL)
		{
			return 0;
		}
		
		return H(n->l)-H(n->r);
	}
	Node *root;
	tree()
	{
		root=NULL;
	}
	int max(int x, int y)
	{
		if(y>x)
		{
			return y;
		}
		return x;
	}
	Node *insert(int ne, Node *head)
	{
		if(head==NULL)
		{
			head=new Node(ne);
			return head;
		}
		 if(ne<head->val)
		{
			head->l=insert(ne,head->l);
		}
		else if(ne>head->val)
		{
			head->r=insert(ne,head->r);
		}
		else
		{
			return head;
		}
		head->height=max(H(head->l),H(head->r))+1;
		
		//balance factor
		int b=balance(head);
		if(b>1 && ne<head->l->val)
		{
//			right-right
			return rightr(head);
		}
//			right-left
		else if(b>1 && ne>head->l->val )
		{
			head->l=leftr(head->l);
			return rightr(head);
		}
//			left-left
		if(b<-1 && ne>head->r->val )
		{
			return leftr(head);
		}
//			left-right
		else if(b<-1 &&ne<head->r->val )
		{
			head->r=rightr(head->r);
			return leftr(head);
		}
		return head;
	}
	
	int H(Node *head)
	{
		
		if(head==NULL)
		{
			return -1;
		}
		else
		{
	   		 return head->height;
		}
	}

	Node* deleten(int v, Node *n)
	{
		if(n==NULL)
		{
			return n;
		}
		
//			1 child
		if(v<n->val)
		{
			n->l=deleten(v,n->l);
		}
		else if(v>n->val)
		{
			n->r=deleten(v,n->r);	
		}
		else 
		{

		    //lst is null so delete node
			if(n->l==NULL)
			{
				Node *t=n->r;
				delete n;
				return t;
			}
			
			//rst is null so delte node
			else if(n->r==NULL)
			{
				Node *t=n->l;
				delete n;
				return t;
			}
	//2 children
	//store min val in a node
	//replace node with min value with the node to delete
	//delete node with in val
        Node* t = min(n->r);
        n->val = t->val;
        n->r = deleten(t->val, n->r);
	}
	
		n->height=max(H(n->l),H(n->r))+1;
		//balance factor
		int b=balance(n);
		if(b>1 && v<n->l->val)
		{
//			right-right
			return rightr(n);
		}
//			right-left
		else if(b>1 && v>n->l->val )
		{
			n->l=leftr(n->l);
			return rightr(n);
		}
//			left-left
		if(b<-1 && v>n->r->val )
		{
			return leftr(n);
		}
		else if(b<-1 && v<n->r->val )
		{
			
			n->r=rightr(n->r);
			return leftr(n);
		}
		return n;
	}

	Node* leftr(Node *n)
	{
		Node *y=n->r;
		Node *z=y->l;
		y->l=n;
		n->r=z;
		n->height=max(H(n->l),H(n->r))+1;
		y->height=max(H(y->l),H(y->r))+1;
		return y;
	}
	Node* rightr(Node *n)
	{
		Node *y=n->l;
		Node *z=y->r;
		//rotation
		y->l=n;
		n->r=z;
		n->height=max(H(n->l),H(n->r))+1;
		y->height=max(H(y->l),H(y->r))+1;
		return y;
	}
	void inorder(Node *t)
	{
		if(t==NULL)
		{
			return;
		}
		inorder(t->l);
		cout<<t->val<<" ";
		inorder(t->r);
	}
	void preorder(Node *t)
	{
		if(t==NULL)
		{
			return;
		}
		cout<<t->val<<" ";
		preorder(t->l);
		preorder(t->r);
	}
	void postorder(Node *t)
	{
		if(t==NULL)
		{
			return;
		}
		postorder(t->l);	
		postorder(t->r);
		cout<<t->val<<" ";
	}
	Node *min(Node *n)
	{
		if(n==NULL)
		{
			return NULL;
		}
		if(n->l==NULL)
		{
			return n;
		}
		return min(n->l);
	}
};

main()
{
	tree t;
	t.root=t.insert(1,t.root);
	t.root=t.insert(2,t.root);
	t.root=t.insert(3,t.root);
	t.root=t.insert(4,t.root);
	t.root=t.insert(5,t.root);
	t.root=t.insert(6,t.root);
	cout<<"In order: ";
	t.inorder(t.root);
	
	cout<<"\nPost order: ";
	t.postorder(t.root);
	
	
	cout<<"\nPre order: ";
	t.preorder(t.root);
	
	t.deleten(4,t.root);
	cout<<"\n\nAfter Deletion of val 4\nIn order: ";
	t.inorder(t.root);
	
	cout<<"\nPost order: ";
	t.postorder(t.root);
	
	
	cout<<"\nPre order: ";
	t.preorder(t.root);
	
	t.deleten(3,t.root);
	cout<<"\n\nAfter Deletion of val 3\nIn order: ";
	t.inorder(t.root);
	
	cout<<"\nPost order: ";
	t.postorder(t.root);
	
	
	cout<<"\nPre order: ";
	t.preorder(t.root);
}
