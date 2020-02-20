#include <iostream>
#include <fstream>
#include <limits>
#include <vector>

using namespace std;

struct Edge // дуга графа 
{
    int to;
    int weight;
};

using Graph = vector<vector<Edge>>;


void DFS(int start, const Graph &graph, vector<bool> &Used, vector<int> &List)// Depth-first search
{
    Used[start] = true;
    for (auto it : graph[start])
    {
        if (!Used[it.to])
            DFS(it.to, graph, Used, List);
    }
    List.push_back(start);
}

vector<int> TopSort(const Graph &graph) // сортировка вершин
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

void GraphPrint(const Graph &graph)
{
    size_t n = graph.size();
    for (size_t i = 0; i < n; ++i)
    {
        size_t m = graph[i].size();
        cout << "v[" << i << "]:\t";
        for (size_t j = 0; j < m; ++j)
        {
            cout << graph[i][j].to << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void makeUndirected(Graph &graph)
{
    bool directed;
    int curr;
    int n = graph.size();
    for (int i = 0; i < n; ++i)
    {
        int m = graph[i].size();
        for (int j = 0; j < m; ++j)
        {
            curr = graph[i][j].to;
            directed = true;
            int p = graph[curr].size();
            for (int k = 0; k < p; ++k)
            {
                if (graph[curr][k].to == i)
                {
                    directed = false;
                }
            }
            if (directed)
            {
                graph[curr].push_back({i, graph[i][j].weight});
            }
        }
    }
}

void edgesSort(Graph &graph)
{
    size_t n = graph.size();
    for (size_t i = 0; i < n; ++i)
    {
        size_t m = graph[i].size();
        for (size_t j = 0; j < m; ++j)
        {
            for (size_t k = 0; k < m - 1; ++k)
            {
                if (graph[i][k].weight > graph[i][k + 1].weight)
                {
                    Edge tmp;
                    tmp = graph[i][k];
                    graph[i][k] = graph[i][k + 1];
                    graph[i][k + 1] = tmp;
                }
            }
        }
    }
}

int main()
{
    int n; // number of vertices
    int m; // number of edges
    int origin;
    int destination;
    int weight;
    int cur_distance;

    ifstream fin("graph.txt", ifstream::in);
    if (!fin.is_open())
    {
        cout << "Error opening file" << endl;
        return -1;
    }
    fin >> n >> m;
    Graph graph(n), graph_reverse(n);
    for (size_t i = 0; i < m; ++i)
    {
        fin >> origin >> destination >> weight;
        graph[origin].push_back({destination, weight});
        graph_reverse[destination].push_back({origin, weight});
    }
    //GraphPrint(graph);
    vector<int> sorted = TopSort(graph);
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

    for (size_t i = 0; i < n; ++i)
    {
        cout << distances[i] << " ";
    }
    cout << endl;
    
    //GraphPrint(graph);
    makeUndirected(graph);
    //GraphPrint(graph);
    edgesSort(graph);
    //GraphPrint(graph);

    return 0;
}
