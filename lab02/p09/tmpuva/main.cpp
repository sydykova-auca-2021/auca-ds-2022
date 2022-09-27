#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int t;
    cin >> t;
    int storeN;
    for(int i = 0; i < t; i++)
    {
        int maxN = 0, minN = 100;
        int N;
        cin >> N;
        for(int j = 0; j < N; j++)
        {
            cin >> storeN;
            maxN = max(storeN, maxN);
            minN = min(storeN, minN);
        }
        cout << 2 * (maxN - minN) << "\n";
    }
}