#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int x, y, test;
    scanf("%d", &test);
    for (int i = 1; i <= test; i++)
    {
        scanf("%d%d", &x, &y);
        int val = (x / 3) * (y / 3);
        printf("%d\n", val);
    }
    return 0;
}
