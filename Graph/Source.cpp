#include <iostream>
#include <fstream>
#include <limits>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int to;
    int weight;
};

struct undirectedEdge
{
    int from;
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

// Topological sort
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

// disjoint-set / union�find data structure
class DSU
{
    public:
    vector<size_t> leaders;
    DSU(size_t n) : leaders(n)
    {
        size_t size = leaders.size();
        for (size_t i = 0; i < size; ++i)
            leaders[i] = i;
    }
    size_t find(size_t v)
    {
        if (leaders[v] != v)
            leaders[v] = find(leaders[v]);
        return leaders[v];
    }
    bool join(size_t u, size_t v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        leaders[v] = u;
        return true;
    }
};

bool comp(undirectedEdge first, undirectedEdge second) 
    { return (first.weight < second.weight); }

int main()
{
    ifstream fin;
    fin.open("graph.txt", ifstream::in);
    //fin.open("C:\\Users\\���������\\source\\repos\\Structs_and_Algs\\Graph\\graph.txt");
    if (!fin.is_open())
    {
        cout << "Error opening file" << endl;
        return -1;
    }

    int n; // number of vertices
    int m; // number of edges
    fin >> n >> m;

    Graph graph(n), graph_reverse(n);
    vector<undirectedEdge> edges(m);
    int origin;
    int destination;
    int weight;

    for (int i = 0; i < m; ++i)
    {
        fin >> origin >> destination >> weight;

        edges[i].from = origin;
        edges[i].to = destination;
        edges[i].weight = weight;

        graph[origin].push_back({destination, weight});
        graph_reverse[destination].push_back({origin, weight});
    }

    int cur_distance;
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

    cout << "������� 1."<< endl
         << "����� ��������� ���������� ���������� �� ��������� �� ������ "
         << "� ������ �� ���������� (������ ������):" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << distances[i] << " ";
    }
    cout << endl << endl;

    DSU set(n);
    sort(edges.begin(), edges.end(), comp);

    cout << "������� 2." << endl
         << "����� ��������� ���� ����������� ��������� �����. "
         << "������ ����� ������� �� ������� ������� �����, "
         << "������ - � ������� ������, "
         << "������ - ��� �����." << endl; 
    for (int i = 0; i < m; ++i)
    {
        if (set.join(edges[i].from, edges[i].to))
            printf(" %3d %3d %2d\n", 
                    edges[i].from, 
                    edges[i].to, 
                    edges[i].weight);
    }
    cout << endl << endl;
    return 0;
}
