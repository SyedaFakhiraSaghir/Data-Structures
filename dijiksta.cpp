#include <iostream>
#include <climits>
using namespace std;

class vertex 
{
    public:
        char name;
        int i;
        int visited;
};

class graph {
public:
    int vert;          // number of vertices
    int **adjmatrix;    // matrix
    vertex *vertices;   // names
    int i = 0;
    bool *visited;
    int *distance;

    graph(int v) 
    {
        vert = v;
        adjmatrix = new int *[vert];
        for (int i = 0; i < vert; i++) 
        {
            adjmatrix[i] = new int[vert]{0};
        }
        vertices = new vertex[vert];
        visited = new bool[vert];
        distance = new int[vert];
        for (int i = 0; i < vert; i++) 
        {
            distance[i]=INT_MAX;
            visited[i] = 0;
        }
    }

    void insertvertex(char name, int key) 
    {
        vertices[i].name = name;
        vertices[i].i = key;
        i++;
    }

    void insertedge(int src, int dest, int weight) 
    {
        adjmatrix[src][dest] = weight;
        adjmatrix[dest][src] = weight;
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

    int minimum() 
    {
        int min = INT_MAX, index;
        for (int i= 0; i< vert; i++) 
        {
            if (visited[i]==0 && distance[i] <= min) 
            {
                min= distance[i];
                index =i;
            }
        }
        return index;
    }

    void Dijkstra(int source, int destination) 
    {
        distance[source] = 0;
        int cost;
        for (int i= 0; i<vert - 1;i++) 
        {
            int u = minimum();
            visited[u]=1;
            for (int j= 0; j<=destination; j++) 
            { 
                if (visited[j]==0 && adjmatrix[u][j] && distance[u]+ adjmatrix[u][j] <distance[j])
                    {
                        distance[j] = distance[u] + adjmatrix[u][j];
                    }
            }
        }
        cout << "\nsource:"<< source << "\tdestination:"<< destination <<endl<<endl;
        for (int i=0;i<=destination;i++) 
        {
            if (i!=source)
                {
                    cout << i << " ["<< distance[i] << "]\n";
                    cost+=distance[i];
                } 
        }
        cout<<"\ncost:"<<cost;
    }
};

int main() {
    int N = 7;
    graph g(N);
    g.insertvertex('A', 0);
    g.insertvertex('B', 1);
    g.insertvertex('C', 2);
    g.insertvertex('D', 3);
    g.insertvertex('E', 4);
    g.insertvertex('F', 5);
    g.insertvertex('G', 6);
    g.insertvertex('H', 7);
    g.insertedge(0, 1, 10);
    g.insertedge(2, 4, 1);
    g.insertedge(2, 5, 9);
    g.insertedge(3, 6, 5);
    g.insertedge(1, 3, 7);
    g.insertedge(0, 2, 6);
    g.insertedge(2, 4, 4);
    g.insertedge(5, 3, 7);
    g.insertedge(5, 2, 6);
    g.insertedge(5, 4, 4);
    g.insertedge(2, 3, 1);
    g.insertedge(3, 2, 7);
    g.insertedge(3, 1, 7);
    g.insertedge(4, 2, 6);
    g.insertedge(6, 4, 4);

    g.displayVertices();
    g.Dijkstra(0,3);
    return 0;
}