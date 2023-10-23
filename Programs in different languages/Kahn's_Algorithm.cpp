/*
Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	// Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[])
	{
		vector<int> res;
		vector<int> indeg(V, 0);
		for (int i = 0; i < V; i++)
		{
			for (auto it : adj[i])
			{
				indeg[it]++;
			}
		}
		queue<int> q;
		for (int i = 0; i < V; i++)
		{
			if (indeg[i] == 0)
				q.push(i);
		}
		while (q.size() != 0)
		{
			int x = q.front();
			q.pop();
			res.push_back(x);
			for (auto it : adj[x])
			{
				indeg[it]--;
				if (indeg[it] == 0)
					q.push(it);
			}
		}
		return res;
	}
};

int main()
{
	int v, e;
	cin >> e >> v;
	vector<int> adj[v];
	for (int i = 0; i < e; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	Solution s;
	vector<int> res = s.topoSort(v, adj);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
	return 0;
}