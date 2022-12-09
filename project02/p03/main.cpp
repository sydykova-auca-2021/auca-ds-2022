#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Freq
{
    int mCount;
    char mLetter;
    
    Freq(char letter, int count)
        : mLetter(letter), mCount(count)
    {
    }
};

bool operator==(Freq const &a, char const &b)
{
    return a.mLetter == b;
}

int main()
{
    iostream::sync_with_stdio(false);

    int cases;
    cin >> cases;

    for (int test = 1; test <= cases; test++)
    {
        int col, row;
        int max, min;
        cin >> row >> col;
        cin >> max >> min;
        vector<Freq> frequences;
    
        for (int i = 0; i < row; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < col; j++)
            {
                auto it = find(begin(frequences), end(frequences), s[j]);
                if (it == frequences.end())
                {
                    frequences.push_back(Freq(s[j], 1));
                }
                else
                {
                    it->mCount = it->mCount + 1;
                }
            }
        }

        sort(begin(frequences), end(frequences), [&](Freq a, Freq b)
            { return a.mCount < b.mCount; });

        int maxVal = ((end(frequences) - 1)->mCount);
        int res = 0;
        auto k = begin(frequences);

        for (; k != end(frequences); k++)
        {
            if ((k->mCount) == maxVal)
            {
                res += ((k->mCount) * max);
            }
            else
            {
                res += ((k->mCount) * min);
            }
        }
        cout << "Case " << test << ": " << res << endl;
    }
}