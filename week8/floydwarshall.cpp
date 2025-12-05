#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void floydWarshall(vector<vector<int>> &dist) 
{
    int V = dist.size(); 

  
    for (int k = 0; k < V; k++) 
    {
        for (int i = 0; i < V; i++) 
        {
            for (int j = 0; j < V; j++) 
            {
                
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                    dist[i][k] + dist[k][j] < dist[i][j]) 
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    
    cout << "\nShortest distances between every pair of vertices:\n";
    cout << "  ";
    for (int i = 0; i < V; i++) cout << char(i + 97) << " ";
    cout << endl;
    for (int i = 0; i < V; i++) 
    {
        cout << char(i + 97) << " ";
        for (int j = 0; j < V; j++) 
        {
            if (dist[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() 
{
    const int INF = INT_MAX;
    int V = 4;
    
    vector<vector<int>> graph = {
        {0,   3, INF,  5},
        {2,   0, INF,  4},
        {INF, 1,   0, INF},
        {INF, INF, 2,   0}
    };

    floydWarshall(graph);
    return 0;
}
