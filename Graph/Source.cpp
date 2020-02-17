#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
using namespace std;

struct Edge
{
    int to;
    int weight;
};

using Graph = vector<vector<Edge>>;

// Depth-first search
void DFS(int start, const Graph &graph, vector<bool> &Used, vector<int> &List)
{
    Used[start] = true;

    for (auto it : graph[start])
    {
        if (!Used[it.to])
            DFS(it.to, graph, Used, List);
    }
    List.push_back(start);
}

vector<int> TopSort(const Graph &graph)
{
    vector<int> sorted;
    vector<bool> Used(graph.size());
    for (size_t i = 0; i < graph.size(); ++i)
    {
        if (!Used[i])
            DFS(i, graph, Used, sorted);
    }
    return sorted;
}

int main()
{
    int n; // число вершин
    int m; // число дуг
    int origin; 
    int destination;
    int weight;
    int cur_distance;

    ifstream fin("graph.txt");
    fin >> n >> m;
    Graph graph(n), graph_reverse(n);
    for (size_t i = 0; i < m; ++i)
    {
        fin >> origin >> destination >> weight;
        graph[origin].push_back({destination, weight});
        graph_reverse[destination].push_back({origin, weight});
    }

    auto sorted = TopSort(graph);

    vector<int> distances(n, numeric_limits<int>::max());
    distances[sorted[0]] = 0;

    for (auto v : sorted)
    {
        for (auto u : graph_reverse[v])
        {
            cur_distance = distances[v] + u.weight;
            if (distances[u.to] > cur_distance)
                distances[u.to] = cur_distance;
        }
    }

    for (auto it : distances)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}