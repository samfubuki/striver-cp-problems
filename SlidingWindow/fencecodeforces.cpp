#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int h[n];
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
    }
    int sum = 0;
    int windowsum = 0;
    int index = k-1;
    for(int i=0;i<k;i++)
    {
        sum = h[i]+sum;
    }
    windowsum = sum;
    for(int j=k;j<n;j++)
    {
      windowsum = windowsum + h[j]-h[j-k];
      if(windowsum<sum)
      {
          windowsum = sum;
          index=j;
      }
    }
   cout<<(index-k+2);
  return 0;


}
