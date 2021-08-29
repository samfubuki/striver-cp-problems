#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    vector<int> arr(n);
    int mid = n/2;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<long long int> left,right;
    for(int i=0;i<(1<<mid);i++)
    {
        long long int sum = 0;
        for(int j=0;j<32;j++)
        {
            if(i & (1<<j))
            {
                sum = sum + arr[j];
            }
        }
      left.push_back(sum);
    }
    int rem = n-mid;
    for(int i=0;i<(1<<rem);++i)
    {
            long long int sum = 0;
            for(int j=0;j<32;++j) {
                if(i & (1<< j))
                    sum += arr[mid+j];
            }
            right.push_back(sum);
    }
    long long int cnt=0;
     sort(right.begin(),right.end());
        for(int i=0;i<left.size();++i){
            cnt += upper_bound(right.begin(),right.end(), x - left[i]) - lower_bound(right.begin(),right.end(), x - left[i]);
        }
        cout << cnt << '\n';
    return 0;
}
