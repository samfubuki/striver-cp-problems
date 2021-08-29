#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adj[100005];
void push(int u, int v)
{
    adj[u].push_back(make_pair(v,0));
    adj[v].push_back(make_pair(u,1));
}
vector<int> ans(100005,INT_MAX);
int visited[100005];
void shortestpath()
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push(make_pair(0,1));
    visited[1]=1;
    while(!pq.empty())
    {
        pair<int,int> p = pq.top();
        int node = p.second;
        int value = p.first;
        pq.pop();
        for(auto a:adj[node])
        {
            int t = a.second+value;
            if(ans[a.first]>t)
            {
                ans[a.first]=t;
                pq.push(make_pair(t,a.first));
            }
        }
    }
}
int main()
{
    int node,edge;
    cin>>node>>edge;
    while(edge--)
    {
        int u,v;
        cin>>u>>v;
        push(u,v);
    }
    shortestpath();
    if(ans[node]==INT_MAX)
    {
        cout<<"-1"<<endl;
    }
    else
    {
        cout<<ans[node]<<endl;
    }
return 0;
}



