#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int r, n;
    int counter = 1;
    while (true)
    {
        cin >> r >> n;
        if (r == 0 && n == 0)
        {
            break;
        }
        --r;
        if (r <= n)
        {
            cout << "Case " << counter << ": 0\n";
        }
        else if (r / n > 26)
        {
            cout << "Case " << counter << ": "
                 << "impossible" << endl;
        }
        else
        {
            cout << "Case " << counter << ": " << r / n << endl;
        }
        counter++;
    }
}