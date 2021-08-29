#include<bits/stdc++.h>
using namespace std;
void precompute(vector<int> &no_of_prime_divisors_till, int n)
{
    vector<int> largest_prime_factor(n,0);
    vector<int> no_of_prime_divisors(n,0);
    for(int i=2;i<n;i++)
    {
        if(largest_prime_factor[i]==0)
        {
            for(int j=i;j<n;j=j+i)
            {
                largest_prime_factor[j]=i;
            }
        }
      int p = largest_prime_factor[i];
      no_of_prime_divisors[i]=1+no_of_prime_divisors[i/p];
      no_of_prime_divisors_till[i]=no_of_prime_divisors[i]+no_of_prime_divisors_till[i-1];
    }

}
int main()
{
    const int n = 5e6+1;
    vector<int> no_of_prime_divisors_till(n,0);
    precompute(no_of_prime_divisors_till,n);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",no_of_prime_divisors_till[a]-no_of_prime_divisors_till[b]);
    }
 return 0;
}
