#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    
    int n, m;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
        {
            cout << "0 0\n";
            break;
        }
        vector<int> v(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> v[i];
        }
        sort(begin(v), end(v), [&](int &first, int &second)
        {
            int mod1 = first % m;
            int mod2 = second % m;
            if (mod1 < mod2)
            {
                return true;
            }
            else if (mod1 == mod2)
            {
                if (abs(first % 2) == 1)
                {
                    if (abs(second % 2 == 0))
                    {
                        return true;
                    }
                    return first > second;
                }
                else if (first % 2 == 0)
                {
                    if (second % 2 == 0)
                    {
                        return first < second;
                    }
                }
            }
            return false; 
        });
        cout << n << " " << m << '\n';
        for (auto e : v)
        {
            cout << e << '\n';
        }
    }
}