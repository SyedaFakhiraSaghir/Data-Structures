#include <iostream>
#include <stack>
#include <queue>
using namespace std;
class vertex 
{
public:
    char name;
    int visited;
};

class graph 
{
public:
    int vert;          // number of vertices
    int **adjmatrix;    // matrix
    vertex *vertices;   // names
    int i = 0;

    graph(int v) 
	{
        vert = v;
        adjmatrix = new int *[vert];
        for (int i = 0; i < vert; i++) 
		{
            adjmatrix[i] = new int[vert]{0};
        }
        vertices = new vertex[vert];
    }

    void insertvertex(char name) 
	{
        vertices[i].name = name;
        i++;
    }

    void insertedge(int src, int dest) 
	{
        adjmatrix[src][dest] = 1;
        adjmatrix[dest][src] = 1;
    }

    void displayVertices() 
    {
        cout << "Vertices in the graph : ";
        for (int j = 0; j < vert; j++) 
        {
            cout << vertices[j].name << "\t";
        }
        cout << endl;
    }

    void BFS(int start) 
    {
        queue<int> q;
        for (int j = 0; j < vert; j++) 
        {
            vertices[j].visited = 0;
        }
        vertices[start].visited = 1;
        q.push(start);
        while (!q.empty()) 
		{
            int u= q.front();
            q.pop();
            cout << vertices[u].name << " ";
            for (int i=0; i<vert; i++) 
            {
                if (adjmatrix[u][i]==1 && vertices[i].visited == 0)
                {
                    vertices[i].visited = 1;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }

    void DFS(int start) 
    {
        stack<int> s;
        for (int j = 0; j < vert; j++) 
        {
            vertices[j].visited = 0;
        }
        s.push(start);
        while (!s.empty()) 
        {
            int u= s.top();
            s.pop();
            if (vertices[u].visited == 0) 
            {
                cout << vertices[u].name << " ";
                vertices[u].visited = 1;
            }
            for (int i = 0; i < vert; i++) 
            {
                if (adjmatrix[u][i] == 1 && vertices[i].visited == 0) 
                {
                    s.push(i);
                }
            }
        }
        cout << endl;
}


};

int main() 
{
    int N=7;
    graph g(N);
    g.insertvertex('A');
    g.insertvertex('B');
    g.insertvertex('C');
    g.insertvertex('D');
    g.insertvertex('E');
    g.insertvertex('F');
    g.insertvertex('G');
    g.insertedge(0, 1);
    g.insertedge(0, 2);
    g.insertedge(2, 3);
    g.insertedge(2, 4);
    g.insertedge(2, 5);
    g.insertedge(3, 6);
    g.insertedge(1, 3);
    g.insertedge(0, 2);
    g.insertedge(2, 4);

    g.displayVertices();
    cout << "\nBreadth First Traversal : ";
    g.BFS(0);
    
    cout << "\nDepth First Traversal : ";
    g.DFS(0);

    return 0;
}