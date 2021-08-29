#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> adj;
vector<int> par;
vector<bool> vis;
void bfs()
{
    vis[1]=true;
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto v: adj[u])
        {
            if(!vis[v])
            {
                vis[v]=true;
                par[v]=u;
                q.push(v);
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    adj.resize(n+1);
    vis.resize(n+1);
    par.resize(n+1);
    for(int i=0;i<=n;i++)
    {
        par[i]=-1;
    }
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    bfs();
    if(par[n]==-1)
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    int candidate=n;
    stack<int> st;
    while(candidate!=-1)
    {
        st.push(candidate);
        candidate = par[candidate];
    }
    cout<<st.size()<<endl;
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
 return 0;
}

