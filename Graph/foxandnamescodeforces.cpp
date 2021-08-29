#include<bits/stdc++.h>
using namespace std;
vector<string> s(105);
vector<int> adj[26];
vector<int> order;
bool flag = false;
bool leftflag = false;
bool visited[105];
bool recurstack[105];
void dfs(int x, int parent)
{
    if(visited[x]==false)
    {
        visited[x]=true;
        recurstack[x]=true;
        for(int u=0;u<adj[x].size();u++)
        {
            int v = adj[x][u];
            if(visited[v]==true && recurstack[v]==true)
            {
                flag=true;
            }
           if(!visited[v])
           {
               dfs(v,x);
           }
        }
        recurstack[x]=false;
        order.push_back(x);
    }

}
int main()
{
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
      string x;
      cin>>x;
      s[i]=x;
  }
  for(int i=0;i<105;i++)
  {
      visited[i]=false;
      recurstack[i]=false;
  }
  for(int i=0;i<n-1;i++)
  {
      string x = s[i];
      string y = s[i+1];
      int co=0;
      for (int j = 0; j < min(x.length(), y.length()); j++) {
           if(x[i]==y[i])
            co++;
       if (x[j] != y[j])
      {
        int p = x[j] - 'a';
        int q = y[j] - 'a';
        adj[p].push_back(q);
        break;
      }
      if(x.length()>y.length()&& co==min(x.length(),y.length()))
      {
        leftflag=true;
      }
  }
  }
  for(int i=0;i<=25;i++)
  {
      dfs(i,-1);
  }
  if(flag==true || leftflag==true)
  {
    cout<<"Impossible"<<endl;
   }
  else
      {
          for(int i=order.size()-1;i>=0;i--)
          {
              cout<<char(order[i]+'a');
          }
        cout<<" "<<endl;
      }

return 0;
}
