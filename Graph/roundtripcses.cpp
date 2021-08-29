#include<bits/stdc++.h>
using namespace std;
int n,m;
int sp,ep;
vector<vector<int>> adj;
vector<int> vis;
vector<int> parent;
bool dfs(int u, int p)
{
    vis[u]=true;
    parent[u]=adj;
    for(auto v:adj[u])
    {
        if(v==p)
        {
            continue;
        }
        if(vis[v])
        {
            sp=v;
            ep=u;
            return true;
        }
        if(!vis[v])
        {
            if(dfs(v,u))
            {
                return true;
            }
        }
    }
  return false;
}
bool visit_all()
{
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(dfs(i,-1))
            {
                return true;
            }
        }
    }
  return false;
}
int main()
{
  cin>>n>>m;
  adj.resize(n+1);
  vis.resize(n+1);
  parent.resize(n+1);
  for(int i=0;i<m;i++)
  {
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
  }
  if(!visit_all())
  {
      cout<<"IMPOSSIBLE"<<endl;
      return 0;
  }
  int tp=ep;
  vector<int> ans;
  ans.push_back(ep);
  while(tp!=ep)
  {
      ans.push_back(parent[tp]);
      tp = parent[tp];
  }
  ans.push_back(ep);
  cout<<ans.size()<<endl;
  for(auto c: ans)
  {
      cout<<c<<" ";
  }
 return 0;
}
