#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{

    int nTestcase, nWall, nHighJumps, nLowJumps, i;
    int height[50] = {0};

    cin >> nTestcase;
    for (i = 1; i <= nTestcase; ++i)
    {
        cin >> nWall;

        for (int j = 0; j < nWall; j++)
        {
            cin >> height[j];
        }
        nHighJumps = 0;
        nLowJumps = 0;

        for (int k = 0; k < nWall - 1; k++)
        {
            if (height[k + 1] < height[k])
            {
                ++nLowJumps;
            }
            else if (height[k + 1] > height[k])
            {
                ++nHighJumps;
            }
        }
        cout << "Case " << i << ": " << nHighJumps << " " << nLowJumps << "\n";
    }
    iostream::sync_with_stdio(false);

    return 0;
}