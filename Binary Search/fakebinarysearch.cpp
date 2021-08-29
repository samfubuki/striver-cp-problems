#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    long long int n,q,x;
	    cin>>n>>q;
	    vector<long long int> a(n);
	    vector<long long int> b(n);
	    map<long long int,long long int> mp;
	    for(long long int i=0;i<n;i++)
	    {
	        cin>>a[i];
	        b[i]=a[i];
	        mp[a[i]]=i;
	    }
	    sort(b.begin(),b.end());
	    while(q--)
	    {
	        cin>>x;
	        long long int smallcnt=0,largecnt=0,mid,low,high,idx,reqsmall=0,ans=0,reqlarge=0;
	        auto it = lower_bound(b.begin(),b.end(),x);
	        idx = mp[x];
	        smallcnt = it-b.begin();
	        largecnt = b.end()-it-1;
	        low=0,high=n-1;
	        while(low<=high)
	        {
	            mid=(low+high)/2;
	            if(mid==idx)
	            {
	                break;
	            }
	            else if(mid<idx)
	            {
	                if(x<a[mid])
	                {
	                    reqsmall++;
	                }
	                else
	                {
	                    smallcnt--;
	                }
	                low=mid+1;
	            }
	            else
	            {
	                if(x>a[mid])
	                {
	                    reqlarge++;

	                }
	                else
	                {
	                    largecnt--;
	                }
	               high=mid-1;
	            }


	        }
	        if(reqsmall<=smallcnt && reqlarge<=largecnt)
	        {
	            ans = min(reqlarge,reqsmall)+abs(reqsmall-reqlarge);
	            cout<<ans<<endl;
	        }
	        else
	        {
	            cout<<-1<<endl;
	        }

	    }
	}
	return 0;
}
