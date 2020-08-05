#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
//#define bint int1024_t
#define ld long double
#define vect vector<ll>
#define unmap unordered_map
#define pb push_back
#define F first
#define pll pair<ll,ll>
#define S second
#define pi 3.1415926536
#define mod int(1e9+7)
#define mp make_pair
//ios_base::sync_with_stdio(false);cin.tie(NULL);
#define testcases ll t; cin>>t; while(t--)

using namespace std;
//using namespace boost::multiprecision;
//using namespace __gnu_pbds;

ll cal(ll x, ll y)
{
    return ((((y%mod)*(x%mod))%mod)*(x%mod))%mod;
}

ll  N = 10000000;
vect v(N+5,1);
vect dp(N+5,0);
vect pref(N+5,0);

void solve()
{
    ll l, r;
    cin>>l>>r;

    ll j = 1;
    //cout<<1<<endl;

    ll x = 1, y = N, f = 0;

    while(x <= y)
    {
        ll m = (x+y) / 2;

        if(pref[m] <= r)
        {
            if(pref[m] == r) f = 1;
            j = m;
            x = m + 1;
        }
        else y = m - 1;
    }

    if(f) j--;

    ll i=0;
    x = 0, y = N+4, f = 0;
    while(x <= y)
    {
        ll m = (x+y) / 2;

        if(pref[m] <= l)
        {
            if(pref[m] == l) f = 1;
            i = m;
            x = m + 1;
        }
        else y = m - 1;
    }

    i++;
    if(!f) i++;

    //cout<<i << " "<<j<<endl;
    ll ans = (dp[j] - dp[i-1] + mod)%mod;

    ans += cal(j+1,r - pref[j]);
    ans %= mod;

    i--;

    ans += cal(i,pref[i] - l + 1);
    ans %= mod;

    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pref[1] = 1;
    dp[1] = 1;
    for (int i = 2; i <= N+4; i++)
    {
        v[i] = 1LL + v[i-v[v[i-1]]];

        dp[i] = cal(i,v[i]);
        dp[i] += dp[i-1];
        dp[i] %= mod;
        pref[i] = (pref[i-1] + v[i]);
    }
    //cout<<pref[800004]<<" ";
    testcases solve();
    return 0;
}
