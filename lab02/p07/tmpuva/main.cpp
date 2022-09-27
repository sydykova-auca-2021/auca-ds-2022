#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int a, b, num1, num2, val;

    while (cin >> a >> b, a != -1 && b != -1)
    {
        if (a > b)
        {
            num1 = a - b;
            num2 = b + 100 - a;
        }
        else
        {
            num1 = b - a;
            num2 = a + 100 - b;
        }
        val = min(num1, num2);

        cout << val << endl;
    }
}