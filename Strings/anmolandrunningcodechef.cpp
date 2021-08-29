#include<bits/stdc++.h>
using namespace std;
void constructarray(int pat[], int m, int lps[])
{
    int len=0;
    int i;
    lps[0]=0;
    i=1;
    while(i<m)
    {
        if(pat[i]==pat[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len=lps[len-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
}
void kmpsearch(int pat[], int txt[], int m, int n, int &ans)
{
    int lps[m];
    int j=0;
    constructarray(pat,m,lps);
    int i=0;
    while(i<n)
    {
        if(pat[j]==txt[i])
        {
            j++;
            i++;
        }
        if(j==m)
        {
            ans++;
            j=lps[j-1];
        }
        else if(i<n && pat[j]!=txt[i])
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                i=i+1;
            }
        }
    }
}
int main()
{
    int t,n,k,ans=0;
    cin>>t;
    while(t--)
    {
      cin>>n>>k;
      int a1[n],a[n-1],d[k];
      for(int i=0;i<n;i++)
      {
          cin>>a1[i];
      }
      for(int i=0;i<k;i++)
      {
          cin>>d[i];
      }
      for(int i=0;i<n-1;i++)
      {
          a[i]=a1[i+1]-a1[i];
      }
      kmpsearch(d,a,k,n,ans);
      cout<<ans<<endl;
      ans=0;
    }
 return 0;
}
