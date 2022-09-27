#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        if ((n1 > n2) & (n1 < n3))
        {
            cout << "Case " << i << ": " << n1 << "\n";
        }
        else if ((n1 > n3) & (n1 < n2))
        {
            cout << "Case " << i << ": " << n1 << "\n";
        }
        else if ((n2 > n1) & (n2 < n3))
        {
            cout << "Case " << i << ": " << n2 << "\n";
        }
        else if ((n2 > n3) & (n2 < n1))
        {
            cout << "Case " << i << ": " << n2 << "\n";
        }
        else if ((n3 > n1) & (n3 < n2))
        {
            cout << "Case " << i << ": " << n3 << "\n";
        }
        else if ((n3 > n2) & (n3 < n1))
        {
            cout << "Case " << i << ": " << n3 << "\n";
        }
        else
            cout << "Case " << i << ": " << n3 << "\n";
    }
}