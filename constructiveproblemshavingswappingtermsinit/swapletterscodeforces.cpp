#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i, j, k;
    int n, m, q;
    string s, t;

    cin>>n;
    cin >> s >> t;

    vector<int> vec1, vec2;
    for(i = 0; i < n; i++)
    {
        if(s[i] == 'a' && t[i] == 'b')
            vec1.push_back(i);

        else if(s[i] == 'b' && t[i] == 'a')
            vec2.push_back(i);
    }

    if(vec1.size() % 2 != vec2.size() % 2)
    {
        cout<<"-1";
        return 0;
    }

    vector<pair<int,int> > ans;
    while(vec1.size() && vec1.size() > 1)
    {
        j = vec1.back();
        vec1.pop_back();

        k = vec1.back();
        vec1.pop_back();

        swap(s[j], t[k]);
        ans.push_back({j, k});
    }

    while(vec2.size() && vec2.size() > 1)
    {
        j = vec2.back();
        vec2.pop_back();

        k = vec2.back();
        vec2.pop_back();

        swap(s[j], t[k]);
        ans.push_back({j, k});
    }

    while(vec1.size() && vec2.size())
    {
        j = vec1.back();
        vec1.pop_back();

        k = vec2.back();
        vec2.pop_back();

        swap(s[j], t[j]);
        swap(s[j], t[k]);

        ans.push_back({j, j});
        ans.push_back({j, k});
    }

    cout<<(ans.size())<<endl;
    for(auto x : ans)
        cout<<(x.first+1)<<" "<<(x.second+1)<<endl;

    return 0;
}
