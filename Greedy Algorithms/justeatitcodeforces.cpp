#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long int t;
   cin>>t;
   while(t--)
   {
       long long int n;
       cin>>n;
       long long int arr[n];
       for(long long int i=0;i<n;i++)
       {
           cin>>arr[i];
       }
       long long int l=0,r=0;
       bool flag=0;
       for(long long int i=0;i<n;i++)
       {
           l=l+arr[i];
           r=r+arr[n-1-i];
           if(l<=0 || r<=0)
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
   }
  return 0;
}
