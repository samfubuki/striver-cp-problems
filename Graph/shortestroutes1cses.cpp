#include<bits/stdc++.h>
using namespace std;
long long int n,m;
vector<vector<pair<long long int,long long int>>> adj;
vector<long long int> dist;
const long long int maxN = 1e17;
void dijkstra()
{
    for(long long int i=0;i<=n;i++)
    {
        dist[i]=maxN;
    }
    priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int>>,greater<pair<long long int,long long int>> > pq;
    dist[1]=0;
    pq.push({0,1});
    while(!pq.empty())
    {
        long long int u = pq.top().second;
        long long int d = pq.top().first;
        pq.pop();
        if(dist[u]<d)
        {
            continue;
        }
        for(auto p:adj[u])
        {
            long long int v = p.first;
            long long int c = p.second;
            if(dist[v]<=c+d)
            {
                continue;
            }
            else
            {
                dist[v]=c+d;
                pq.push({dist[v],v});
            }
        }
    }
}
int main()
{
  cin>>n>>m;
  adj.resize(n+1);
  dist.resize(n+1);
  for(auto i =0;i<m;i++)
  {
      long long int u,v,c;
      cin>>u>>v>>c;
      adj[u].push_back({v,c});
  }
  dijkstra();
  for(long long int i=1;i<=n;i++)
  {
      cout<<dist[i]<<" ";
  }
 return 0;
}
