#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t=0;
    while(1)
    {
        t++;
        string s;
        cin>>s;
        if(s[0]=='-')
        {
            break;
        }
        stack<char> st;
        int i,j,k,l=s.size();
        for(int i=0;i<l;i++)
        {
            if(s[i]=='{')
                {
                    st.push(s[i]);
                }
            else
            {
                if(st.size())
                {
                    if(st.top()=='{')
                        {
                            st.pop();
                        }
                    else
                    {
                        st.push(s[i]);
                    }
                }
                else
                {
                    st.push(s[i]);
                }
            }
        }
        int s1=0,s2=0;
        while(st.size())
        {
            if(st.top()=='}')
                {
                  s2++;
                }
             else
             {
                 s1++;

             }
             st.pop();
        }
        if((s1%2==0) && (s2%2==0))
        {
            cout << "\n" << t << ". " <<((s1+s2)/2);

        }
        else if((s1%2!=0) && (s2%2!=0))
        {
            cout << "\n" << t << ". " <<((s1+s2)/2+1);
        }
    }
 return 0;
}
