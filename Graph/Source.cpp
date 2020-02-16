//#include <iostream>
//#include "graph.h"
//#include <vector>
//using namespace std;
//
//struct Edge 
//{
//    int to;
//    int w;
//};
//
//using Graph = vector<vector<Edge>>;
//
//void DFS(int start, const Graph &graph, vector<int> &List, vector<int> &Used) 
//{
//    Used[start] = true;
//    for (auto it : graph[start]) 
//    {
//        if (!Used[it.to]) 
//        {
//            DFS(it.to, graph, List, Used);
//        }
//    }
//    List.push_back(start);
//}
//
//vector<int> TopSort(const Graph& graph) 
//{
//    vector<int> List, Used(graph.size());
//    for (int i = 0; i < graph.size(); ++i) 
//    {
//        if (!Used[i]) 
//        {
//            DFS(i, graph, List, Used);
//        }
//    }
//    return List;
//}
//
//
//
//int main() 
//{
//    int n, m;
//    cin >> n >> m;
//
//    Graph graph(n);
//
//    for (int i = 0; i < m; ++i) 
//    {
//        int u, v, w;
//
//        cin >> u >> v >> w;
//        graph[u].push_back({v, w});
//    }
//
//    auto sorted = TopSort(graph);
//    
//    for (auto it:sorted) 
//    {
//        cout << it << " ";
//    }
//    cout << endl;
//
//    return 0;
//}

#include <iostream>
#include <vector>
using namespace std;

struct Edge 
{
	int to, weight;
};

using Graph = vector<vector<Edge>>;

void DFS(int start, const Graph& graph, vector<bool>& Used, vector<int>& List) 
{
	Used[start] = true;
	
	for (auto it : graph[start]) 
	{
		if (!Used[it.to])
			DFS(it.to, graph, Used, List);
	}
	List.push_back(start);
}

vector<int> TopSort(const Graph& graph) 
{
	vector <int> sorted;
	vector <bool> Used(graph.size());
	for (size_t i=0; i<graph.size(); ++i) 
	{
		if (!Used[i])
			DFS(i, graph, Used, sorted);
	}
	return sorted;
}

int main() 
{
	int n, m;
	cin >> n >> m; // число вершин/дуг
	Graph graph(n), graph_reverse(n);
	for (size_t i = 0; i < m; ++i) 
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
		graph_reverse[v].push_back({ u,w });
	}

	auto sorted = TopSort(graph);

	vector<int>distances(n, numeric_limits<int>::max());
	distances[sorted[0]] = 0;
	
	for (auto v : sorted) 
	{
		for (auto u : graph_reverse[v]) 
		{
			auto cur_distance = distances[v]+ u.weight;
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