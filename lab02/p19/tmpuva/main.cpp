#include <bits/stdc++.h>

template <typename C>

int sz(const C &c)
{
    return static_cast<int>(c.size());
}

using namespace std;

int main()

{
    iostream::sync_with_stdio(false);

    int t;
    cin >> t;
    cin.ignore();

    for (int i = 0; i < t; i++)
    {
        int counter = 0;
        string track;
        getline(cin, track);
        for (auto it = track.begin(); it != track.end(); it++)
        {
            if (*it == 'M')
            {
                counter++;
            }
            else if (*it == 'F')
            {
                counter--;
            }
        }

        if (counter == 0 && track.length() > 3)
        {
            cout << "LOOP"
                 << "\n";
        }
        else
        {
            cout << "NO LOOP"
                 << "\n";
        }
    }
}