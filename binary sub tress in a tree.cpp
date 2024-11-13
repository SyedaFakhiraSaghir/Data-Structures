//Q6: Given an integer n, return at most n + 1 OR maximum unique BST's (binary search trees), which have exactly n nodes of unique values from 1 to n. Return the answer in any order.
//Example (For n = 3)

#include<iostream>
using namespace std;

class Node{
	public:
		int val;
		Node *r;
		Node *l;
		Node *next;
		Node()
		{
			val=0;
			r=NULL;
			l=NULL;
			next=NULL;
		}
		Node(int x)
		{
			val=x;
			r=NULL;
			l=NULL;
			next=NULL;
		}
};

class queue{
	
	public:
		
		Node *head;//front
		Node *tail;//rear
		
		queue()
		{
			head=NULL;
			tail=NULL;
		}
		
		void push(Node *& n)
		{
			if(head==NULL)
			{
				head=n;
				tail=n;
			}
			else{
				head->next=n;
				head=n;
			}
		}
		
		Node* pop()//dequeue at tail
		{
			Node *temp = tail;
			tail = tail->next;
			return temp;
		}
	
		bool isempty()
		{
		    if(head==NULL && tail==NULL)
		    {
		        return true;
		    }
		    return false;
		}
};

class tree
{
	public:
		Node *root;
		int minv=-999;
		int maxv=999;
		
		tree()
		{
			root=NULL;
		}
		
		void insert(int ne)
		{
			Node *n=new Node(ne);
			queue q;
			if(root==NULL)
			{
				root=n;				
			}
			else
			{
			q.push(root);
			while(!q.isempty())
			{
			    Node *temp=q.pop();
			    
				if(temp->l!=NULL)
				{
					q.push(temp->l);
				}
				else
				{
					temp->l=n;
					return;
				}
				if(temp->r!=NULL)
				{
					q.push(temp->r);
				}
				else
				{
					temp->r=n;
					return;
				}
			}
			}
			
		}
		int H(Node *head)
    	{
    		
    		if(head==NULL)
    		{
    			return -1;
    		}
    		else
    		{
    	   		 return max(H(head->l),H(head->r))+1;
    		}
    	}

		void display(Node *t)
		{
			if(t==NULL)
			{
				return;
			}
			cout<<t->val<<" ";
			display(t->l);
			display(t->r);
		}
		
		bool bst(Node *n, int min, int max, int num)
		{
		    if(n==NULL || num==0)
		    {
		        return true;
		        
		    }
		    if(n->val>=min || n->val<=max)
		    {
				display(n);
				cout<<endl;
		    	return bst(n->l, min, n->val,num-1) && bst(n->r, n->val,max,num-1);
		    }
		    return false;
		}
		
};

main()
{
	tree t;
	int n;
	cout<<"\nN: ";
	cin>>n;
	for(int i=1;i<n+1;i++)
	{
		t.insert(i);
	}
	t.display(t.root);
	
	cout<<endl;
	cout<<"subtrees:";
	t.bst(t.root,t.minv,t.maxv,n+1);
	cout<<"lst subtrees:";
	t.bst(t.root->l,t.minv,t.maxv,n+1);
	cout<<"\nrst subtrees:"<<endl;
	t.bst(t.root->r,t.minv,t.maxv,n+1);
}