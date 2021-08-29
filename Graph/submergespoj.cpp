#include<bits/stdc++.h>
#define maxN 10005
using namespace std;
int n,m;
int cnt,times;
vector<int> v[maxN];
bool visited[maxN],ap[maxN];
int parent[maxN];
int low[maxN],disc[maxN];
void init()
{
    cnt=0;
    times=0;
    for(int i=0;i<maxN;i++)
    {
        ap[i]=false;
        v[i].clear();
        visited[i]=false;
        parent[i]=-1;
    }
}
void dfs(int u)
{
    int children=0;
    visited[u]=true;
    int l = v[u].size();
    disc[u]=low[u]=++times;
    for(int i=0;i<l;i++)
    {
        int v1 = v[u][i];
        if(!visited[v1])
        {
            ++children;
            parent[v1]=u;
            dfs(v1);
            low[u]=min(low[u],low[v1]);
            if(parent[u]==-1 && children>1)
            {
                ap[true];
            }
            //no backedge
            if(parent[u]!=-1 && disc[u]<=low[v1])
            {
                ap[u]=true;
                cnt++;
            }
        }
        else
        {
            if(v1!=parent[u])
            {
                low[u]=min(low[u],disc[v1]);
            }
        }
    }
}
void fun()
{
    for(int i=1;i<n+1;i++)
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }
}
int main()
{
  int a,b;
  while(1)
  {
      init();
      cin>>n>>m;
      if(!n && !m)
      {
          break;
      }
      for(int i=0;i<m;i++)
      {
          cin>>a>>b;
          v[a].push_back(b);
          v[b].push_back(a);
      }
      fun();
      cnt=0;
      for(int i=1;i<n+1;i++)
      {
          if(ap[i])
          {
              cnt++;
          }
      }
      cout<<cnt<<endl;
  }
}
