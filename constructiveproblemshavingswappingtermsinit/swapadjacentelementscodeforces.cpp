#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  {
      cin>>arr[i];
  }
  string s;
  cin>>s;
  int maxi=0;
  bool flag=0;
  for(int i=0;i<n;i++)
  {
      maxi=max(maxi,arr[i]);
      if(s[i]=='0' && maxi>i+1)
      {
          flag=1;
          break;
      }
  }
 if(flag==1)
 {
     cout<<"NO"<<endl;
 }
 else
 {
     cout<<"YES"<<endl;
 }
 return 0;
}
