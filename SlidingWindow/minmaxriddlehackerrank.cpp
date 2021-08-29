#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the riddle function below.
vector<long > riddle(vector<long> arr) {
   stack<pair<long,long>> st;

   unordered_map<long,long> mp;

    for(long i=0;i<arr.size();i++)
    {
        mp[arr[i]] = 0;
    }

    for(long i=0;i<arr.size();i++)
    {
        if(st.empty())
        {
            st.push(make_pair(arr[i],1));
            continue;
        }

        if(st.top().first<arr[i])
        {
            st.push(make_pair(arr[i],1));
            continue;
        }
        long cnt=0;
        while(!st.empty() && st.top().first>=arr[i])
        {
            cnt+=st.top().second;
            long temp = st.top().first;
            mp[temp] =cnt;

            st.pop();
        }
        cnt++;
        st.push(make_pair(arr[i],cnt));
    }
    long cnt=0;
    while(!st.empty())
    {
        cnt+=st.top().second;
        long temp = st.top().first;
        mp[temp] = cnt;
        st.pop();
    }
    unordered_map<long,long> mp2;
    for(auto itr=mp.begin();itr!=mp.end();itr++)
    {
        if(mp2.find(itr->second)==mp2.end())
        {
            mp2[itr->second] = itr->first;
        }
        else
        {
            mp2[itr->second] = max(mp2[itr->second],itr->first);
        }
    }


    vector<long> ans;

    long prev = -1;
    for(long i=arr.size();i>=1;i--)
    {
        if(mp2.find(i)!=mp2.end() && mp2[i]>prev)
        {
            ans.push_back(mp2[i]);
            prev = mp2[i];
            continue;
        }
        ans.push_back(prev);
    }
    reverse(ans.begin(),ans.end());
    return ans;


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<long> res = riddle(arr);

    for (int i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

