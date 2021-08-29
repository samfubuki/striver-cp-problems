#include<bits/stdc++.h>
using namespace std;
vector<int> cal(string input , int n)
{
    vector<int> z(n);
    int left=0;
    int right=0;
    z[0]=0;
    for(int k=1;k<n;k++)
    {
        if(k>right)
        {
            left=right-k;
            while(right<n && input[right]==input[right-left])
            {
                right++;
            }
            z[k]=right-left;
            right--;
        }
        else
        {
            int k1 = k-left;
            if(z[k1]<right-k+1)
            {
                z[k]=z[k1];
            } else {
                left=k;
                while(right<n && input[right]==input[right-left])
                {
                    right++;
                }
               z[k]=right-left;
               right--;
            }

        }
    }
  return z;
}
int main()
{
    string a;
    cin>>a;
    vector<int> z = cal(a,a.length());
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(z[n]>n)
        {
            cout<<n<<endl;
        }
        else
        {
            cout<<z[n]<<endl;
        }
    }
 return 0;
}
