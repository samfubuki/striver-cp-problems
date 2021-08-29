#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    cin>>k;
    vector<long long int> a(10,1);
    long long int cnt=1;
    long long int i=0;
    while(cnt<k)
    {
        long long int ok = a[i%10];
        cnt = cnt/ok;
        a[i%10]++;

        cnt=cnt*a[i%10];
        i++;
    }
    string str = "codeforces";
    for(long long int i=0;i<10;i++)
    {
        for(long long int j=0;j<a[i];j++)
        {
            cout<<str[i];
        }
    }
 return 0;
}
