#include<bits/stdc++.h>
using namespace std;
void lcs(string x, string y, int m, int n)
{
    int t[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
            {
                t[i][j]=0;
            }
            else if(x[i-1]==y[j-1])
            {
                t[i][j]=t[i-1][j-1]+1;
            }
            else
            {
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    int index = t[m][n];
    char lcs[index];
    lcs[index]='\0';
    int i=m,j=n;
    while(i>0 && j>0)
    {
        if(x[i-1]==y[j-1])
        {
            lcs[index-1]=x[i-1];
            i--;
            j--;
            index--;
        }
        else if(t[i-1][j]>t[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    cout<<lcs;
}
int main()
{
    string x,y;
    cin>>x;
    cin>>y;
    int m = x.length();
    int n = y.length();
    lcs(x,y,m,n);
    return 0;
}
