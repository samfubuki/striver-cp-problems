#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> degree;
priority_queue<int,vector<int>,greater<int>> indegno;
vector<vector<int>> adj;
int main()
{
   int n,m;
   cin>>n>>m;
   adj.resize(n+1);
   degree.resize(n+1);
   for(int i=0;i<m;i++)
   {
       int u,v;
       cin>>u>>v;
       adj[u].push_back(v);
       ++degree[v];
   }
   for(int i=1;i<=n;i++)
   {
       if(!degree[i])
       {
           indegno.push(i);
       }
   }
   vector<int> ans;
   while(!indegno.empty())
   {
       int u = indegno.top();
       indegno.pop();
       ans.push_back(u);
       for(auto v:adj[u])
       {
           --degree[v];
           if(!degree[v])
           {
               indegno.push(v);
           }
       }
   }
   if(ans.size()!=n)
   {
      cout<<"IMPOSSIBLE"<<endl;
   }
   else
   {
       for(auto u:ans)
       {
           cout<<u<<" ";
       }
   }
 return 0;
}
