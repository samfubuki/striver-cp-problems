#include<bits/stdc++.h>
using namespace std;
long long int n,m,q;
vector<vector<long long int>> adj;
long long int maxn = 1e15;
int main()
{
   cin>>n>>m>>q;
   adj.resize(n+1);
   for(long long int i=0;i<=n;i++)
   {
       adj[i].resize(n+1);
   }
   for(long long int i=1;i<=n;i++)
   {
       for(long long int j=i+1;j<=n;j++)
       {
           adj[i][j]=adj[j][i]=maxn;
       }
   }
   for(long long int i = 0; i < m; ++i)
	{
		long long int u, v, c;
		cin >> u >> v >> c;
		adj[u][v] = adj[v][u] = min(adj[u][v],c);
	}

	for(long long int k = 1; k <= n; ++k)
	{
		for(long long int i = 1; i <= n; ++i)
		{
			for(long long int j = 1; j <= n; ++j)
			{
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}

	for(long long int i = 0; i < q; ++i)
	{
		long long int u, v;
		cin >> u >> v;
		if(adj[u][v] == maxn)
			adj[u][v] = -1;
		cout << adj[u][v] << endl;
	}
 return 0;
}
