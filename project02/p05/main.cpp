#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <iterator>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct PairSecond
{
    int mAscii;
    int mFreq;
    PairSecond(int ascii, int freq)
        : mAscii(ascii), mFreq(freq)
    {
    }
    bool operator==(const int p) const { return this->mAscii == p; }
};

int freqs[200];

int main()
{
    string line;
    int z = 1;
    int asValue;
    while (getline(cin, line))
    {
        iostream::sync_with_stdio(false);

        if (z == 0)
            cout << endl;
        vector<PairSecond> pairs;

        for (size_t i = 0; i < line.length(); ++i)
        {
            char c = line[i];
            asValue = c;
            auto aschiIt = find(pairs.begin(), pairs.end(), asValue);
            if (aschiIt == pairs.end())
            {
                pairs.push_back(PairSecond(asValue, 1));
            }
            else
            {
                aschiIt->mFreq++;
            }
        }

        sort(begin(pairs), end(pairs), [](const PairSecond &p1, const PairSecond &p2)
        {  
            if (p1.mFreq < p2.mFreq)
                return true;
            else if(p1.mFreq == p2.mFreq)
                return p1.mAscii > p2.mAscii;
            else 
                return false; 
        });
        for (auto i = pairs.begin(); i != pairs.end(); i++)
        {
            cout << i->mAscii << " " << i->mFreq << endl;
        }
        z = 0;
    }
}