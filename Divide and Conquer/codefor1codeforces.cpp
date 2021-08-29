#include<bits/stdc++.h>
using namespace std;
long long int n,l,r;
long long int solve(long long int n, long long int left, long long int right)
{
    if (left > r || right < l) return 0;
    if (n < 2) {
        if (left >= l && right <= r)
        {
          return n;
        }
        else
        {
          return 0;
        }
    }
    long long int mid = (left + right) >> 1;
    return solve(n / 2, left, mid - 1) + solve(n % 2, mid, mid) + solve(n / 2, mid + 1, right);
}
int main()
{

    cin>>n>>l>>r;
    long long int len=1;
    while(len<n)
    {
      len=2*len+1;
    }
    cout<<solve(n,1,len)<<endl;

}
