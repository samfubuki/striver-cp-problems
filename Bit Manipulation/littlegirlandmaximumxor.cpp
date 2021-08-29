#include<bits/stdc++.h>
using namespace std;
long long all_ones(int n)
{
    return (1LL << (n + 1)) - 1;
}
int main()
{
    long long int left,right;
    cin>>left>>right;
    if(left==right)
    {
        cout<<"0"<<endl;
        return 0;
    }
    int largest_unequal_bit_position;
    for(int i=0; left>0 || right>0;i++)
    {
        if(left%2 != right%2)
        {
            largest_unequal_bit_position = i;

        }
        left>>=1;
        right>>=1;
    }
    long long int answer = all_ones(largest_unequal_bit_position);

    cout<<answer;
  return 0;
}
