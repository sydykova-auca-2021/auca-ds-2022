#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Skill
{
    int price;
    string job;
    Skill(const string &j, int &p)
        : job(j), price(p)
    {
    }
};

int main()
{
    iostream::sync_with_stdio(false);

    int n, m, price;
    cin >> n;
    cin >> m;
    string job;
    vector<Skill> v;

    for (int i = 0; i < n; ++i)
    {
        cin >> job;
        cin >> price;
        v.push_back(Skill(job, price));
    }

    sort(begin(v), end(v), [](const Skill &a, const Skill &b)
        { return a.job < b.job; });

    for (int i = 0; i < m; ++i)
    {
        string s;
        int sum = 0;

        while (cin >> s && s != ".")
        {
            for (auto e : v)
            {
                if (s == e.job)
                {
                    sum += e.price;
                }
            }
        }
        cout << sum << '\n';
    }
}