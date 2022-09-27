#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int testCases, n;
    cin >> testCases;
    for (int i = 0; i < testCases; i++)
    {
        cin >> n;
        long long res = (((((n * 567) / 9) + 7492) * 235) / 47) - 498;
        long long tens = (res / 10) % 10;
        cout << abs(tens) << endl;
    }
    return 0;
}