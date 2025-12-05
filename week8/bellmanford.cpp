#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void bellmanFord(vector<vector<int>> &graph, int src) 
{
    int V = graph.size();
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    
    for (int count = 1; count <= V - 1; count++) 
    {
        for (int u = 0; u < V; u++) 
        {
            for (int v = 0; v < V; v++) 
            {
                if (graph[u][v] != INT_MAX && dist[u] != INT_MAX && 
                    dist[u] + graph[u][v] < dist[v]) 
                {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

   
    for (int u = 0; u < V; u++) 
    {
        for (int v = 0; v < V; v++) 
        {
            if (graph[u][v] != INT_MAX && dist[u] != INT_MAX && 
                dist[u] + graph[u][v] < dist[v]) 
            {
                cout << "Graph contains a negative weight cycle!\n";
                return;
            }
        }
    }

   
    cout << "\nVertex Distance from Source (" << char(src + 97) << "):\n";
    for (int i = 0; i < V; i++) 
    {
        cout << char(i + 97) << "\t";
        if (dist[i] == INT_MAX)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }
}

int main() 
{
    const int INF = INT_MAX;
    int V = 5;

    
    vector<vector<int>> graph = {
        {0,   6,   INF, 7,   INF},
        {INF, 0,   5,   8,  -4},
        {INF, -2,  0,   INF, INF},
        {INF, INF, -3,  0,   9},
        {2,   INF, 7,   INF, 0}
    };

    bellmanFord(graph, 0); 
    return 0;
}
