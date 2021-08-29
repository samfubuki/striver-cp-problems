#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int arr[n][m],ans[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            ans[i][j]=1;
        }

    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]==0)
            {
                for(int k=0;k<n;k++)
                {
                    ans[k][j]=0;
                }
                for(int k=0;k<m;k++)
                {
                    ans[i][k]=0;
                }
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==1)
            {
             bool flag=false;
             for(int k=0;k<n;k++)
             {
                 if(ans[k][j]==1)
                 {
                     flag=true;
                 }
             }
             for(int k=0;k<m;k++)
             {
                 if(ans[i][k]==1)
                 {
                     flag=true;
                 }
             }
             if(!flag)
             {
                 cout<<"NO"<<endl;
                 return 0;
             }
            }
        }
    }
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<ans[i][j]<<" ";
            }
          cout<<endl;
        }
return 0;
}
