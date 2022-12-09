#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<pair<int, string>> v;
    string s1, s2;

    while (n--)
    {
        cin >> s1 >> s2;
        if (isalpha(s1[0])) 
        {
            v.emplace_back(stoi(s2), s1);
        }
        else
        {
            v.emplace_back(stoi(s1) / 2, s2);
        }
    }
    sort(begin(v), end(v));

    for (auto e : v)
    {
        cout << e.second << '\n';
    }
}