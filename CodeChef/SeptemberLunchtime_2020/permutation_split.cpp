#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

mt19937 rng((long long) (new char));
const int N = 100 + 7;
int n;
int a[N];
int d[N];
bool ok[N * N];

void tc()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        d[i] = 0;
    }
    int invs = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (a[i] > a[j])
            {
                invs++;
                d[i]++;
                d[j]++;
            }
        }
    }
    for (int i = 0; i <= n * n; i++)
    {
        ok[i] = 0;
    }
    ok[0] = 1;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = sum; j >= 0; j--)
        {
            if (ok[j])
            {
                ok[j + d[i]] = 1;
            }
        }
        sum += d[i];
    }
    if (ok[invs])
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        tc();
    }

}

