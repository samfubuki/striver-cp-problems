#include<bits/stdc++.h>
using namespace std;
#define maxN 200005

int n, m, x,q,u,v;


int level[maxN];
vector<int> adj[maxN];
int jump[21][maxN];

void dfs(int u, int p, int l)
{
    jump[0][u] = p;
    level[u] = l;

	for (int v: adj[u])
		if(v != p)
		dfs(v, u, l+1);
}

void preprocess_LCA()
{
	dfs(1, -1, 0);

	for (int i = 1; 1<<i <= n ; i++)
	for (int j = 0; j <= n ; j++)
	jump[i][j] = jump[i-1][jump[i-1][j]];
}

int LCA(int p,int q)
{
	if(level[p] < level[q])
	swap(p, q);

	int diff = level[p] - level[q];

	for(int i = 20; i >= 0; i--)
		if(diff & (1<<i))
		p = jump[i][p];

	if(p == q) return p;

	for (int i = 20; i >= 0; i--) {
		if (jump[i][p] != jump[i][q]) {
			p = jump[i][p];
			q = jump[i][q];
		}
	}
	return jump[0][p];
}


int main()
{
    cin >> n >> q;
    for(int i = 2; i <= n; i++) {
        cin >> u;
        adj[u].push_back(i);
        adj[i].push_back(u);
    }
    preprocess_LCA();
    while(q--) {
        cin >> u >> v;
        cout << LCA(u, v) << endl;
    }
  return 0;
}
