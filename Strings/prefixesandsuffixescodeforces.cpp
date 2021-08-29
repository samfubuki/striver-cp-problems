#include<bits/stdc++.h>
using namespace std;
const int maxlen = 100005;
char s[maxlen];
char z[maxlen];
int c[maxlen];
int main()
{
    scanf("%s",s);
    int n = strlen(s);
    z[0]=n;
    int l=0,r=0;
    for(int i=1;i<n;i++)
    {
        if(r<i)
        {
            l=r=i;
            while(s[r]==s[r-l])
            {
                r++;
            }
          z[i]=r-l;
        }
        else
        {
            int b = r-i;
            int j = i-l;
            if(z[j]<b)
            {
                z[i]=z[j];
            }
            else if(z[j]>b)
            {
                z[i]=b;
            }
            else
            {
                l=i;
                r=i+b;
                while(s[r]==s[r-l])
                {
                    r++;
                }
               z[i]=r-l;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        c[i]=z[i];
    }
    sort(c,c+n);
    int length=1;
    vector< pair<int , int > > ans;
    for(int i=n-1;i>=0;i--)
    {
        if(z[i]==length)
        {
            int t = (c+n)-lower_bound(c,c+n,length);
            ans.push_back(make_pair(length,t));
        }
      length++;
    }
    printf("%d\n",ans.size());
     for (pair<int, int> p : ans)
     {
        printf("%d %d\n", p.first, p.second);
     }
 return 0;
}
