#include<bits/stdc++.h>
using namespace std;
long long int maxSubArray(vector<long long int>& nums) {
        long long int sum = 0;
        long long int maxi = INT_MIN;
        for(long long int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            maxi = max(sum, maxi);
            if(sum<0)
            {
                sum = 0;
            }
        }
     return maxi;
}
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        vector<int> a(n);
        long long int sum_even = 0;
        for(long long int i=0;i<n;i++)
        {
            cin>>a[i];
            if(i%2==0)
            {
                sum_even = sum_even + a[i];
            }
        }
        vector<long long int> even;
        vector<long long int> odd;
        for(long long int i=0;i<n-1;i=i+2)
        {
            even.push_back(a[i+1]-a[i]);
        }
        for(long long int i=1;i<n-1;i=i+2)
        {
            odd.push_back(a[i]-a[i+1]);
        }
     long long int b = maxSubArray(even);
     long long int c = maxSubArray(odd);
     cout<<sum_even+max({0LL,b,c})<<endl;

    }
 return 0;
}
