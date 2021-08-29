#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n,k;
        cin>>k;
        long long int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        long long int min_index = 1;
        long long int max_peak = 0;
        for(long long int i=2;i<k;i++)
        {
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
            {
                max_peak++;
            }
        }
        long long int last_peak = max_peak;
        for(long long int i=k+1;i<n;i++)
        {
            long long int p = last_peak;
            if(arr[i-k+1]>arr[i-k] && arr[i-k+1]>arr[i-k+2])
            {
                p--;
            }
            if(arr[i-1]>arr[i-2] && arr[i-1]>arr[i])
            {
                p++;
            }
           if(p>max_peak)
           {
               max_peak=p;
               min_index = i-k+1;

           }
           last_peak=p;
        }
       cout<<max_peak+1<<" "<<min_index<<endl;

    }
 return 0;
}
