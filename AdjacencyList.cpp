#include<bits/stdc++.h>
using namespace std;

/* Input:
	n -> number of nodes (constant)
	m -> number of edges

	n m
	m lines

	5 6
	1 2
	1 3
	3 4
	2 4
	2 5
	4 5
*/

int main()
{
	int n, m; cin >> n >> m;
	vector<int> adjList[n + 1];
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		/*
			for weighted graph:
			vector<pair<int, int>> adjList[n + 1];
			pair -> {node2, weight}
			int weight; cin >> weight;
			adjList[node1].push_back({node2, weight});
		*/
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	return 0;
}
