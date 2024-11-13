#include <iostream>
#include <climits>
#include <stack>
#include <queue>
using namespace std;

class vertex {
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
    int *MST;
    bool *visited;
    int *NMST;
    int **edges; 
    int totaledges;
    int *distance;
    
    graph(int v) {
        vert = v;
        totaledges=v-1;
        adjmatrix = new int *[vert];
        for (int i = 0; i < vert; i++) {
            adjmatrix[i] = new int[vert]{0};
        }
        vertices = new vertex[vert];
        MST = new int[v];
        NMST = new int[v];
        visited = new bool[v];
        distance = new int[vert];
        edges = new int *[vert * vert];
        for (int i = 0; i < vert; i++) {
            NMST[i] = 999;
            visited[i] = 0;
            MST[i] = -1;
            distance[i]=INT_MAX;
        }
        for (int i = 0; i < vert * vert; i++) {
            edges[i] = new int[3];
        }
    }

    void insertvertex(char name, int key) {
        vertices[i].name = name;
        vertices[i].i = key;
        i++;
    }

    void insertedge(int src, int dest, int weight) 
	{
        adjmatrix[src][dest] = weight;
        adjmatrix[dest][src] = weight;
        edges[totaledges][0] = src;
        edges[totaledges][1] = dest;
        edges[totaledges][2] = weight;
        totaledges++;
    }

    void displayVertices() {
        cout << "\nVertices in the graph : ";
        for (int j = 0; j < vert; j++) {
            cout << vertices[j].name << "\t";
        }
        cout << endl;
    }

    int EP(int a) //smallest weight of all edges
    {
        while (MST[a] != a) 
        {
            MST[a] = MST[MST[a]];
            a =MST[a];
        }
        return a;
    }

    int min() {
        int low = 999, i;
        for (int v = 0; v < vert; v++) {
            if (visited[v] == 0 && NMST[v] < low) {
                low = NMST[v];
                i = v;
            }
        }
        return i;
    }

    void mst() {
        NMST[0] = 0, MST[0] = -1;
        for (int i = 0; i < vert - 1; i++) {
            int u = min();
            visited[u] = 1;
            for (int v = 0; v < vert; v++) {
                if (adjmatrix[u][v] != 0 && visited[v] == 0 && adjmatrix[u][v] < NMST[v]) {
                    MST[v] = u;
                    NMST[v] = adjmatrix[u][v];
                }
            }
        }
        int minweight = 0;
        for (int i = 1; i < vert; i++) {
            cout << "[" << MST[i] << "," << i << "] : " << adjmatrix[i][MST[i]] << endl;
            minweight = minweight + adjmatrix[i][MST[i]];
        }
        cout << "Minimum weight: " << minweight;
    }

    void kruskals() 
    {
        int count = 0, sum = 0;
        for (int i = 0; i <totaledges-1; i++) //sorting edges
        {
            for (int j = 0; j < totaledges-1; j++) 
            {
                if ( edges[j][2] > edges[j + 1][2] ) //if weight of current index > weight of next index swap
                {
                    swap(edges[j][2], edges[j + 1][2]);
                }
            }
        }
        //sorted vertices in MST
        for (int i = 0; i < vert; i++)
        {
            MST[i] = i;
        }
        //finding minimal path
        for( i=0; i < totaledges;i++) 
        {
        	if(count< vert-1)
        	{
	            int p1= EP(edges[i][0]);//source
	            int p2= EP(edges[i][1]);//destination
	            if (p1 != p2) //if source not equals destination
	            {
	                MST[p1] = p2;
	                cout << "[" << edges[i][0] << "," << edges[i][1] << "] : " << edges[i][2] << "\n";
	                sum += edges[i][2];
	                count++;
	            }
	        }
	        else 
	        {
	        	break;
			}
        }
        cout << "\nweight of the MST: " << sum;
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
    	for (int i = 0; i < vert; i++) {
            NMST[i] = 999;
            visited[i] = 0;
            MST[i] = -1;
            distance[i]=INT_MAX;
        }
        distance[source] = 0;
        int cost=0;
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
    void BFS(int start) 
    {
    	for (int i = 0; i < vert; i++) {
            NMST[i] = 999;
            visited[i] = 0;
            MST[i] = -1;
            distance[i]=INT_MAX;
        }
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
                if (adjmatrix[u][i] && vertices[i].visited == 0)
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
    	for (int i = 0; i < vert; i++) {
            NMST[i] = 999;
            visited[i] = 0;
            MST[i] = -1;
            distance[i]=INT_MAX;
        }
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
                if (adjmatrix[u][i] && vertices[i].visited == 0) 
                {
                    s.push(i);
                }
            }
        }
        cout << endl;
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
    g.insertedge(0, 1, 10);
    g.insertedge(0, 2, 20);
    g.insertedge(2, 3, 2);
    g.insertedge(2, 4, 1);
    g.insertedge(2, 5, 9);
    g.insertedge(3, 6, 5);
    g.insertedge(1, 3, 7);
    g.insertedge(0, 2, 6);
    g.insertedge(2, 4, 4);
    g.displayVertices();
    cout << "\nPrim's Algorithm:\n";
    g.mst();
    cout << "\n\nKruskal's Algorithm:\n";
    g.kruskals();
    g.displayVertices();
    g.Dijkstra(0,6);
    cout<<"\nBFS:";
    g.BFS(0);
    cout<<"\nDFS:";
    g.DFS(0);
    return 0;
}