#include <iostream>
using namespace std;

/*Given an array of N integers, and an integer K, find the number of pairs of elements in the
array whose sum is equal to K. Use Hashing (time complexity should not be more than N worst
case)
Input:
N = 4, K = 6
arr[] = {1, 5, 7, 1}
Output: 2
Explanation:
arr[0] + arr[1] = 1 + 5 = 6
and arr[1] + arr[3] = 5 + 1 = 6.*/

class Hashmaptable;
class Node{
	public:
		int x;
		int key;
		Node *next;
		
		Node()
		{
			x=0;
			next=NULL;
		}
		
		Node(int x, int k)
		{
			this->x=x;
			key=k;
			next=NULL;
		}
};

class list{
	public:
	Node *head;
	
	list()
	{
		head=NULL;
	}
	
	list(Node *n)
	{
		head=n;
	}
	
	//delete by value
	void dbv(int k,int value)
	{
	    Node *u=head;
		if(head!=NULL)
		{
		  if(value==head->key && k==head->x){
		    head=u->next;
			delete u;
			u=NULL;
			return;}
		}
 		Node *n;
		Node *t= head;
		while(t->next->next!=NULL )
		{
			if(value==t->next->x && k==t->next->key)
			{
			 n=t->next;
			 t->next=t->next->next;
			 n=NULL;
			 delete n;
			}
			t=t->next;
		}
	}
		
	void appendnode(int key,int data)
	{
		Node *n=new Node(data,key);
		if(head==NULL)
		{
			head=n;
		}
		else
		{
			Node *ptr=head;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=n;
		}
	}
	
	void d()
	{
		Node *ptr=head;
		while(ptr!=NULL)
		{
		    cout<<ptr->x<<"->";
			ptr=ptr->next;
		}
		cout<<"NULL"<<endl;
	}
	
	void search(int v)
	{
		Node *t=head;
		while(t!=NULL)
		{
			if(v==t->x)
			{
			 cout<<"value "<<t->x<<" found\n";
			 return;
			}
			t=t->next;
		}
		cout<<"\n not found\n";
	}
};

class Hashmaptable {
	private:
		int ts;
		list *ll;
	public:
		
		Hashmaptable(int ts)
		{
			this->ts= ts;
			ll= new list[ts];
		}
		Hashmaptable() {}
		
		int HashFunc(int k)
		{
			return k % ts;
		}
		
		void append(int k,int v)
		{
			int index=HashFunc(k);
			ll[index].appendnode(v,k);
		}
		
		void search(int k,int v)
		{
			int index=HashFunc(k);
			ll[index].search(k);
		}
		
		void Remove (int k,int v)
		{
			int index=HashFunc(k);
			ll[index].dbv(k,v);
		}
		
		void display()
		{
			cout<<"-----   H a s h       M a p   -------";
			for(int i=0;i<ts;i++)
			{
				ll[i].d();
				//cout<<endl;
			}
		}
		
		int findsum(int sum) 
	{
	    int *count = new int[ts]{0};
	    int pair = 0;
	    for (int i = 0; i < ts; i++) 
	    {
	        Node* t = ll[i].head;
	        while (t != NULL) 
	        {
	            int current = t->x;
	            int found = sum - current;
	            
	            // Ensure that found is within the valid range
	            if (found >= 0 && found < ts) {
	                pair += count[found];
	            }
	            
	            count[current]++;
	            t = t->next;
	        }
	    }
	
	    // Delete the dynamically allocated array
	    delete[] count;
	
	    return pair;
	}

};

int main()
{
	int n,k;
	cout<<"Enter n : ";
	cin>>n;
	cout<<"\nEnter k : ";
	cin>>k;
	int arr[n];
	
	Hashmaptable h(n*2);
	for(int i=0;i<n;i++)
	{
		cout<<"Enter num "<< i+1 <<" : ";
		cin >> arr[i];
		h.append(arr[i],i);
	}
	h.display();
	
	cout<<endl;
	cout<< h.findsum(k);
	cout<<endl;
	
	return 0;
}