#include <iostream>
#include "graph.h"
#include <vector>
using namespace std;

struct Edge 
{
    int to;
    int w;
};

using Graph = vector<vector<Edge>>;

int main() 
{
    int n, m;
    cin >> n >> m;
    
    Graph graph(n);

    for (int i = 0; i < m; ++i) 
    {
        int u, v, w;

        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    return 0;
}