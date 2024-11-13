#include <iostream>
using namespace std;

class node;

class vertex {
public:
    char name;
    int i;
    bool visited;
    int weight;
    node* head;
    vertex()
    {
        i = 0;
        weight = 9999;
        head = NULL;
        visited = false;
    }
};

class node {
public:
    int weight;
    int i;
    node* next;
    node()
    {
    }
    node(int ind, int w)
    {
        i = ind;
        weight = w;
        next = NULL;
    }
};

class graph {
public:
    int vert; // number of vertices
    vertex* vertices;
    vertex* neighbours;
    int i;
    graph(int v)
    {
        vert = v;
        vertices = new vertex[vert];
        neighbours = new vertex[vert];
        i = 0;
    }

    void insertvertex(char n, int k)
    {
        vertices[k].name = n;
        vertices[k].i = k;
        i++;
    }

    void insertedge(int src, int dest, int weight)
    {
        if (neighbours[src].head == NULL)
        {
            neighbours[src].head = new node(dest, weight);
        }
        else
        {
            node* t = neighbours[src].head;
            while (t->next != NULL)
            {
                t = t->next;
            }
            t->next = new node(dest, weight);
        }
        if (neighbours[dest].head == NULL)
        { 
			neighbours[dest].head = new node(src, weight);
		}
	    else
        {
            node* t = neighbours[dest].head;
            while (t->next != NULL)
            { t = t->next; }
            t->next = new node(src, weight);
        }
    }

    void displayVertices()
    {
        for (int i = 0; i < vert; i++)
        {
            if (neighbours[i].head != NULL)
            {
                node* t = neighbours[i].head;
                cout<<vertices[i].name<<" : ";
                while (t != NULL)
                {
                    cout << t->i << "[" << t->weight << "] ";
                    t = t->next;
                }
                cout << endl;
            }
        }
    }
};

int main()
{
    int N = 7;
    graph g(N);
    g.insertvertex('A', 0);
    g.insertvertex('B', 1);
    g.insertvertex('C', 2);
    g.insertvertex('D', 3);
    g.insertvertex('E', 4);
    g.insertvertex('F', 5);
    g.insertvertex('G', 6);
    g.insertedge(0, 1, 10);
    g.insertedge(0, 2, 6);
    g.insertedge(0, 2, 20);
    g.insertedge(2, 3, 2);
    g.insertedge(2, 4, 1);
    g.insertedge(2, 5, 9);
    g.insertedge(3, 6, 5);
    g.insertedge(1, 3, 7);
    g.insertedge(2, 4, 4);

    g.displayVertices();
    return 0;
}