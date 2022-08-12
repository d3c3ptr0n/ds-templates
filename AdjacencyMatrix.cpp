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
	int adjMatrix[n + 1][n + 1];
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		/*
			for weighted graph:
			int weight; cin>>weight;
			adjMatrix[node1][node2] = weight;
		*/
		adjMatrix[u][v] = 1;
		adjMatrix[v][u] = 1;
	}
	return 0;
}
