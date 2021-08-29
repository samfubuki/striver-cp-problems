#include<bits/stdc++.h>
using namespace std;
vector<int> tree[200001];
int diameter[200001];
int downPath[200001];
void calc_downpaths(int src , int par)
{
    int bestchilddownpath = 0;
    bool leaf = 1;
    for(int child:tree[src])
    {
        if(child!=par)
        {
            leaf=0;
            calc_downpaths(child,src);
            bestchilddownpath = max(bestchilddownpath , downPath[child]);
        }
    }
    if(leaf)
    {
        downPath[src]=0;
    }
    else
    {
        downPath[src] = 1+bestchilddownpath;
    }

}
void solvedp(int src , int par)
{
    int ans = 0;
    vector<int> childrendownpaths;
    for(int child : tree[src])
    {
        if(child!=par)
        {
            solvedp(child,src);
            childrendownpaths.push_back(downPath[child]);
            ans = max(ans,diameter[child]);
        }

    }
    int numofchildren = childrendownpaths.size();
    sort(childrendownpaths.begin(),childrendownpaths.end());
    if(numofchildren==0)
    {
        diameter[src]=0;
    }
    else if(numofchildren==1)
    {
        diameter[src] = 1 + childrendownpaths[0];
    }
    else
    {
        diameter[src] = 2 + childrendownpaths[numofchildren-1] + childrendownpaths[numofchildren-2];
    }
   diameter[src] = max(diameter[src],ans);
}
int main()
{

    long long int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    calc_downpaths(1,0);
    solvedp(1,0);
    cout<<diameter[1]<<endl;
  return 0;
}
