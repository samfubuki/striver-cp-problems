#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e5+5;
vector<pair<int,int>> cost[maxN];
int vis[maxN],par[maxN],dist[maxN],n,e;
bool dijkstra(int sp, int ep)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=1;i<=n;i++)
    {
        dist[i]=INT_MAX;
    }
    pq.push(pair<int,int>(0,sp));
    par[sp]=-1;
    dist[sp]=0;
    while(!pq.empty())
    {
        int h = pq.top().second;
        pq.pop();
        if(h==ep)
        {
            return true;
        }
        vis[h]=1;
        for(auto i: cost[h])
        {
            int w = i.second, v = i.first;
            if(!vis[v] && (dist[h]+w<dist[v]))
            {
                dist[v]=dist[h]+w;
                pq.push(pair<int,int>(dist[v],v));
                par[v]=h;
            }
        }
    }
  return false;
}
int main()
{
   int u,v,w;
   cin>>n>>e;
   for(int i=0;i<e;i++)
   {
       cin>>u>>v>>w;
       cost[u].push_back(pair<int,int>(v,w));
       cost[v].push_back(pair<int,int>(u,w));
   }
   if(dijkstra(1,n))
   {
       vector<int> path;
       int i=n;
       while(i!=-1)
       {
           path.push_back(i);
           i=par[i];
       }
       for(int i=path.size()-1;i>=0;i--)
       {
           cout<<path[i]<<" ";
       }
       cout<<endl;
   }
   else
   {
       cout<<-1<<endl;
   }
  return 0;
}
