#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int arr[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>arr[i][j];
            }
        }
        bool flag=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int total=0;
                if((i-1)>=0)
                {
                    total++;
                }
                if(i+1<n)
                {
                    total++;
                }
                if((j-1)>=0)
                {
                    total++;
                }
                if(j+1<m)
                {
                    total++;
                }
                if(arr[i][j]>total)
                {
                    flag=1;
                    break;
                }
                arr[i][j]=total;
            }
        }
        if(flag==1)
        {
            cout<<"NO"<<endl;
        }
        else
        {
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<arr[i][j]<<" ";
            }
          cout<<endl;

        }
        }
    }
  return 0;
}
