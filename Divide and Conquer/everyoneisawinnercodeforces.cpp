#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        set<int> st;
        st.insert(0);
        int num = sqrt(n);
        for(int i=1;i<=num;i++)
        {
            st.insert(n/i);
            st.insert(i);
        }
        cout<<st.size()<<endl;
        for(auto i: st)
        {
            cout<<i<<" ";
        }
      cout<<endl;
    }
 return 0;
}
