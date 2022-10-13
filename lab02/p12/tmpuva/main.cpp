#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

void computeDigits(int n, int &sum, int &count)
{
    sum = 0;
    count = 0;

    do
    {
        sum += n % 10;
        ++count;
        n /= 10;
    } while (n != 0);
}

int solve(int n)
{
    int sOfDigits, nOfDigits;
    do
    {
        computeDigits(n, sOfDigits, nOfDigits);
        n = sOfDigits;
    } while (nOfDigits != 1);

    return n;
}

int main()
{
    iostream::sync_with_stdio(false);

    for (int n; cin >> n && n != 0;)
    {
        cout << solve(n) << "\n";
    }
}