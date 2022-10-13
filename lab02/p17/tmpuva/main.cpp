#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int h, w;

    while (cin >> h >> w)
    {
        vector<char> shape(w);
        int halfsquare = 0, area = 0;
        while (h-- > 0)
        {
            for (int i = 0; i < w; ++i)
            {
                cin >> shape[i];
                if (shape[i] == '.')
                {
                    if (halfsquare % 2 == 1)
                    {
                        ++area;
                    }
                }
                else
                {
                    ++halfsquare;
                }
            }
        }
        cout << area + halfsquare / 2 << "\n";
    }
}