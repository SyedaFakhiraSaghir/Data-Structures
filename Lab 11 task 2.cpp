#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class vertex {
public:
    char name;
    int key;
    vertex *next;
    int visited;
    vertex()
    {
    	next=NULL;
	 }
    vertex(char n,int i)
    {
    	name=n;
    	key=i;
    	next=NULL;
	 }
 
};

class graph {
public:
    int vert ; // number of vertices
    vertex * vertices[7]; 
    

    graph(int v) {
        vert = v;
    }

    void insertvertex(char n,int i) {
    	
       vertices[i]=new vertex(n,i);
    
    }

    void insertedge(vertex *src, vertex * dest) {
    	int i=src->key;
    	vertex *temp=vertices[i];
    	vertex *temp2=vertices[dest->key];
    	if (temp==NULL)
    	{
    	vertices[i] = src;
    					return;
		 }
		   if (temp2==NULL)
    	{
    	vertices[dest->key] = dest;
    					return;
		 }
    	while(temp->next!=NULL)
    	{
    		temp=temp->next;
  	
     }
    	  temp->next = new vertex(dest->name, dest->key);
    		while(temp2->next!=NULL)
    	{
    		temp2=temp2->next;
  	
     }
    	  temp2->next = new vertex(src->name, src->key);
    	        
  	
    }
    stack<vertex*>Stack;
queue<vertex*> Queue;
void BFS(vertex *start) 
    {
        for (int j = 0; j < vert; j++) 
        {
            vertices[j]->visited = 0;
        }
        int k=start->key;
        vertices[k]->visited = 1;
        Queue.push(start);
        while (!Queue.empty()) 
		{
            vertex *v= Queue.front();
            Queue.pop();
            cout << v->name << " ";
            vertex *temp=vertices[v->key];
           
           	while(temp!=NULL)
            	{	
            	
           for (int i=0; i<vert; i++) 
            {
            	if(temp->name==vertices[i]->name)
            	{
            		if ( vertices[i]->visited == 0)
                {
              		
                    vertices[i]->visited = 1;
                    Queue.push(temp);
                    break;
                }
                
					}
            
           }
                temp=temp->next;
             }
            
        }
        cout << endl;
    }

 void DFS(vertex *start) 
    {
        for (int j = 0; j < vert; j++) 
        {
            vertices[j]->visited = 0;
        }
        int k=start->key;
        vertices[k]->visited = 1;
        Stack.push(start);
        while (!Stack.empty()) 
		{
            vertex *v=Stack.top();
            Stack.pop();
            cout << v->name << " ";
            vertex *temp=vertices[v->key];
           
           	while(temp!=NULL)
            	{	
            	
           for (int i=0; i<vert; i++) 
            {
            	if(temp->name==vertices[i]->name)
            	{
            		if ( vertices[i]->visited == 0)
                {
              		
                    vertices[i]->visited = 1;
                    Stack.push(temp);
                    break;
                }
                
					}
            
           }
                temp=temp->next;
             }
            
        }
        cout << endl;
    }





    void displayVertices() {
        cout << "Vertices in the graph : ";
        for (int j = 0; j < vert; j++) {
            cout << vertices[j]->name << "\t";
        }
		  cout << endl;
    }

    void printAdjList() {
        cout << "Adjacency List:\n";
        for (int i = 0; i < vert; i++) {
            vertex* temp = vertices[i];
            while (temp != nullptr) {
            cout << temp->name;
                temp = temp->next;
                if (temp != nullptr) {
                    cout << " -> ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
	
    int N = 7;
    graph g(N);
    g.insertvertex('a',0);
    g.insertvertex('b',1);
    g.insertvertex('c',2);
    g.insertvertex('d',3);
    g.insertvertex('e',4);
    g.insertvertex('f',5);
    g.insertvertex('g',6);
    
    g.insertedge(g.vertices[0], g.vertices[1]);
    g.insertedge(g.vertices[0], g.vertices[2]);
    
    g.insertedge(g.vertices[1],g.vertices[2] );
    g.insertedge(g.vertices[1], g.vertices[3]);
    g.insertedge(g.vertices[1], g.vertices[4]);
    
    g.insertedge(g.vertices[2], g.vertices[3]);
    g.insertedge(g.vertices[2], g.vertices[5]);
    
    g.insertedge(g.vertices[3], g.vertices[4]);
    g.insertedge(g.vertices[3], g.vertices[5]);
    
    g.insertedge(g.vertices[4], g.vertices[5]);
    g.insertedge(g.vertices[4], g.vertices[6]);
    
    g.insertedge(g.vertices[5],g.vertices[6]);
   
g.displayVertices();
 g.printAdjList();
  cout << "\nBreadth First Traversal : ";
    g.BFS(g.vertices[0]);
    
    cout << "\nDepth First Traversal : ";
    g.DFS(g.vertices[0]);


    return 0;
}