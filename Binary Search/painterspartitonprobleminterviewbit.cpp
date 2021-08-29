#define mod 10000003
#define ll long long
long long int findfeasible(vector<int> &C, long long int n, long long int limit)
{
    long long int sum=0,painters=1;
    for(long long int i=0;i<n;i++)
    {
        sum = sum + C[i];
        if(sum>limit)
        {
            sum = C[i];
            painters++;
        }
    }
return painters;
}
int Solution::paint(int A, int B, vector<int> &C) {
    long long int total_length=0;
    int k=0;
    for(long long int i=0;i<C.size();i++)
    {
        k=max(k,C[i]);
        total_length=total_length+C[i];

    }
    long long int low=k,high=total_length;
    while(low<high)
    {
        long long int mid = low+(high-low)/2;
        long long int painters = findfeasible(C,C.size(),mid);
        if(painters<=A)
        {
            high=mid;
        }
        else
        {
            low=mid+1;
        }

    }
   return (low*B)% 10000003;

}
