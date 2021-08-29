#include<bits/stdc++.h>
using namespace std;
long long int knapSack(long long int W, long long int wt[], long long int val[], long long int n)
    {
      long long int t[n+1][W+1];
      memset(t,-1,sizeof(t));
      for(long long int i=0;i<n+1;i++)
      {
          for(long long int j=0;j<W+1;j++)
          {
              if(i==0 || j==0)
              {
                  t[i][j]=0;
              }
          }
      }
      for(long long int i=1;i<n+1;i++)
      {
          for(long long int j=1;j<W+1;j++)
          {
              if(wt[i-1]<=j)
              {
                  t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
              }
              else
              {
                  t[i][j]=t[i-1][j];
              }
          }
      }
      return t[n][W];


    }
int main()
{
    long long int n,w;
    cin>>n>>w;
    long long int val[n],wt[n];
    for(long long int i=0;i<n;i++)
    {
        cin>>wt[i]>>val[i];
    }
    cout<<knapSack(w,wt,val,n)<<endl;
 return 0;

}
