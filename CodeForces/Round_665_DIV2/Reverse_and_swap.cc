#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long LL;

LL p, a[528000], ll[528000], rr[528000];

LL SUM(LL l, LL r, LL d)
{
    LL x, y, z;

    x = ll[d];
    y = rr[d];
    z = b & ~(y - x);

    x ^= z;
    y ^= z;

    if(x > r || y < l)
	return 0;

    else if(x < l || y > r)
	return(SUM(l, r, z << 1) + SUM(l, r, (z << 1) + 1));

    else
	return a[z];
}

void REP(LL i,LL k)
{
    i += p;

    for(a[i] = k; i >>= 1;)
	a[i] = (a[i << 1] + a[(i << 1) + 1]);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int b = 0, i, n, q;

    cin >> n >> q;
    p = 1 << n;

    for(i = 0; i < p; i++)
    {
	cin >> a[p + i];
	ll[p + i] = rr[p + i] = i;
    }

    for(; i < p; i++)
	ll[p + i] = rr[p + i] = i;

    for(; --i;)
    {
	a[i] = (a[i << 1] + a[(i << 1) + 1]);
	ll[i] = ll[i << 1];
	rr[i] = rr[(i << 1) + 1];
    }

    for(; q--;)
    {
	int m;

	cin >> m;

	if(m == 1)
	{
	    int k, x;

	    cin >> x >> k;

	    REP((x - 1) ^ b, k);
	}

	else if(m == 2)
	{
	    int k;

	    cin >> k;

	    b ^= (1 << k) - 1;
	}

	else if(m == 3)
	{
	    int k;

	    cin >> k;

	    b ^= 1 << k;
	}

	else
	{
	    int l, r;

	    cin >> l >> r;

	    cout << SUM(l - 1, r - 1, 1) << endl;
	}
    }
}
