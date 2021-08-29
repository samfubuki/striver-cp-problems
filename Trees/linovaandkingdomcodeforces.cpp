#include<bits/stdc++.h>
using namespace std;
const int n = 200005;
int a[n],father[n],cnt_sons[n],level[n],sub_tree[n];
priority_queue<pair<int,int>> Q;
vector<int> edges[n];
void dfs(int node, int fth)
{
   father[node] = fth;
   for(int son: edges[node])
   {
       if(son==fth)
       {
           continue;
       }
       cnt_sons[node]++;
       level[son]=level[node]+1;
       dfs(son,node);
   }
   if(!cnt_sons[node])
   {
       Q.push({level[node],node});
   }
}
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    dfs(0,-1);
    long long int ans=0;
    while(k && !Q.empty())
    {
        pair<int,int> node_pair = Q.top();
        int node_father = father[node_pair.second];
        Q.pop();
        ans = ans + node_pair.first;
        k--;
        sub_tree[node_pair.second]++;
        if(node_father!=-1)
        {
            cnt_sons[node_father]--;
            sub_tree[node_father] += sub_tree[node_pair.second];
            if(cnt_sons[node_father]==0)
            {
                Q.push({level[node_father]-sub_tree[node_father],node_father});
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

