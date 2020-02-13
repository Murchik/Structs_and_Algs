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

void DFS(int start, const Graph &graph, vector<int> &List, vector<int> &Used) 
{
    Used[start] = true;
    for (auto it : graph[start]) 
    {
        if (!Used[it.to]) 
        {
            DFS(it.to, graph, List, Used);
        }
    }
    List.push_back(start);
}

vector<int> TopSort(const Graph& graph) 
{
    vector<int> List, Used(graph.size());
    for (int i = 0; i < graph.size(); ++i) 
    {
        if (!Used[i]) 
        {
            DFS(i, graph, List, Used);
        }
    }
    return List;
}


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

    auto sorted = TopSort(graph);
    
    for (auto it:sorted) 
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
