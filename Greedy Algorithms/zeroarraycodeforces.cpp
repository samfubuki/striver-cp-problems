#include<bits/stdc++.h>
using namespace std;
int main()
{
        long long int n;
        cin>>n;
        long long int arr[n];
        for(long long int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        long long int maxele=-1;
        long long int sum = 0;
        for(long long int i=0;i<n;i++)
        {
            sum = sum+arr[i];
            maxele = max(maxele,arr[i]);
        }
        long long int sum2 = sum-maxele;
        if((sum%2==0) && (maxele<=sum2))
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
 return 0;
}
