#include<bits/stdc++.h>
using namespace std;
const int maxN = 100000;
const int Log = 18;
//const int INF = 1e17;
int parent[maxN][Log];
int minlength[maxN][Log];
int maxlength[maxN][Log];
vector<pair<int,int> > graph[maxN];
int t=0;
int tin[maxN];
int tout[maxN];
void dfs(int root, int par, int minlen, int maxlen)
{
    tin[root]=t++;
    parent[root][0]=par;
    minlength[root][0]=minlen;
    maxlength[root][0]=maxlen;
    for(int i=1;i<Log;i++)
    {
        parent[root][i] = parent[parent[root][i-1]][i-1];
        minlength[root][i] = min(minlength[root][i-1],minlength[parent[root][i-1]][i-1]);
        maxlength[root][i] = max(maxlength[root][i-1],maxlength[parent[root][i-1]][i-1]);
    }
    for(auto child:graph[root])
    {
        if(child.first!=par)
        {
            dfs(child.first,root,child.second,child.second);
        }
    }
    tout[root]=t++;
}
bool isAncestor(int u, int v)
{
    return (tin[u]<=tin[v] && tout[u]>=tout[v]);
}
int Lca(int u, int v)
{
    if(isAncestor(u,v))
    {
        return u;
    }
    if(isAncestor(v,u))
    {
        return v;
    }
    for(int i=Log-1;i>=0;i--)
    {
        if(!isAncestor(parent[u][i],v))
        {
            u = parent[u][i];
        }
    }
  return parent[u][0];
}
pair<int,int> queryoutput(int u, int v)
{
    int lca = Lca(u,v);
    int shortestlength = INT_MAX;
    int longestlength = 0;
    for(int j=Log-1;j>=0;j--)
    {
        if(isAncestor(lca,parent[u][j]))
        {
            shortestlength = min(shortestlength,minlength[u][j]);
            longestlength = max(longestlength,maxlength[u][j]);
            u = parent[u][j];
        }
    }
    for(int j=Log-1;j>=0;j--)
    {
        if(isAncestor(lca,parent[v][j]))
        {
            shortestlength = min(shortestlength,minlength[v][j]);
            longestlength = max(longestlength,maxlength[v][j]);
            v = parent[v][j];
        }
    }
   return make_pair(shortestlength,longestlength);
}
int main()
{
    int n,u,v,d;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        cin>>u>>v>>d;
        graph[u].push_back(make_pair(v,d));
        graph[v].push_back(make_pair(u,d));
    }
    dfs(1,1,INT_MAX,0);
    int q;
    cin>>q;
    while(q--)
    {
        int u,v;
        cin>>u>>v;
        auto answer = queryoutput(u,v);
        cout << answer.first << " " << answer.second << endl;
    }
 return 0;
}
