#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e17;
const int nmaxN = -1*(maxN);
struct triplet{
	int first;
	int second;
	int third;
};

int n, m;
vector<triplet> edges;
vector<int> dist;
void bellman_ford()
{
	for(int i = 1; i < n; ++i)
	{
		for(auto e: edges)
		{
			int u = e.first;
			int v = e.second;
			int d = e.third;
			if(dist[u] == maxN)
            {
              continue;
            }
			dist[v] = min(dist[v], d+dist[u]);
			dist[v] = max(dist[v], nmaxN);
		}
	}

	for(int i = 1; i < n; ++i)
	{
		for(auto e: edges)
		{
			int u = e.first;
			int v = e.second;
			int d = e.third;
			if(dist[u] == maxN) continue;
			dist[v] = max(dist[v], nmaxN);
			if(dist[u]+d < dist[v])
			{
				dist[v] = nmaxN;
			}
		}
	}
}
int main()
{
  cin >> n >> m;
	dist.resize(n+1);
	edges.resize(m);
	for(int i = 0; i < m; ++i)
	{
		struct triplet inp;
		cin >> inp.first >> inp.second >> inp.third;
		inp.third *= -1;
		edges[i] = inp;
	}

	for(int i = 2; i <= n; ++i)
	{
		dist[i] = maxN;
	}

	bellman_ford();
	if(dist[n] == nmaxN)
	{
		cout << -1 << endl;
		return 0;
	}
	cout << dist[n] * (-1) << endl;
 return 0;
}
