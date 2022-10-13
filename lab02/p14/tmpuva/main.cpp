#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{

    iostream::sync_with_stdio(false);

    int n, len;
    cin >> n;
    bool title = true;
    bool order;

    while (n--)
    {
        vector<int> lumberjacks;
        for (int i = 0; i < 10; i++)
        {
            cin >> len;
            lumberjacks.push_back(len);
        }

        if (lumberjacks[0] < lumberjacks[1])
        {
            for (int i = 1; i < sz(lumberjacks) - 1; i++)
            {

                if (lumberjacks[i] < lumberjacks[i + 1])
                {
                    order = true;
                }
                else
                {
                    order = false;
                    break;
                }
            }
        }

        else if (lumberjacks[0] > lumberjacks[1])
        {
            for (int i = 1; i < sz(lumberjacks) - 1; i++)
            {
                if (lumberjacks[i] > lumberjacks[i + 1])
                {
                    order = true;
                }
                else
                {
                    order = false;
                    break;
                }
            }
        }

        if (title)
        {
            cout << "Lumberjacks:" << endl;
            title = false;
        }
        cout << (order ? "Ordered" : "Unordered") << endl;
    }
}