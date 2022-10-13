#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    for (string line; getline(cin, line);)
    {
        istringstream strInp(line);
        bool isFirst = true;
        for (string word; strInp >> word;)
        {
            reverse(word.begin(), word.end());
            cout << (isFirst ? "" : " ") << word;
            isFirst = false;
        }
        cout << "\n";
    }
}