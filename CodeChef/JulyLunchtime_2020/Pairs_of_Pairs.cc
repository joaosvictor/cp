pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1e9+7;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
ll mpow(ll a, ll b){
	if(a==0) return 0;
	if(b==0) return 1;
	ll t1 = mpow(a,b/2);
	t1 *= t1;
	t1 %= MOD;
	if(b%2) t1 *= a;
	t1 %= MOD;
	return t1;
}
 
ll mpow(ll a, ll b, ll p){
	if(a==0) return 0;
	if(b==0) return 1;
	ll t1 = mpow(a,b/2,p);
	t1 *= t1;
	t1 %= p;
	if(b%2) t1 *= a;
	t1 %= p;
	return t1;
}
 
ll modinverse(ll a, ll m){
	ll m0 = m; 
    ll y = 0, x = 1; 
    if (m == 1) return 0; 
    while (a > 1){
        ll q = a / m; 
        ll t = m; 
        m = a % m, a = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    }
    if (x < 0) x += m0; 
    return x; 
}

mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
 
ll range(ll l, ll r){
	return l + mt()%(r-l+1);
}
 
ll rev(ll v){
	return mpow(v,MOD-2);
}

ll ansarr[10];

void solve(){
	ll n;
	cin >> n >> MOD;
	if(n<10){
		cout << ansarr[n]%MOD << ln;
		return;
	}
	ll fact[2*n+1];
	fact[0]=1;
	forsn(i,1,2*n+1) fact[i] = (fact[i-1]*i)%MOD;
	ll den[n+1];
	den[0]=1;
	forsn(i,1,n+1) den[i] = (den[i-1]*2*i)%MOD;
	ll f[n+1];
	ll inv3 = rev(3);
	forn(i,n+1) f[i]=(fact[2*i]*rev(den[i]))%MOD;
	ll fby3[n+1];
	forn(i,n+1)  fby3[i]=(f[i]*inv3)%MOD;
	fby3[1]=0;
	// cout << f[1] << " " << f[2] << " " << f[3] << " " << f[4] << ln;
	// cout << fby3[1] << " " << fby3[2] << " " << fby3[3] << " " << fby3[4] << ln;
	ll g[n+1];
	g[1]=1;
	forsn(i,2,n+1){
		g[i]=f[i];
		forsn(j,1,i){
			g[i]-=g[j]*f[i-j];
			g[i]%=MOD;
		}
	}
	forsn(i,2,n+1){
		fby3[i] *= ((i*(i-1))/2);
		fby3[i] %= MOD;
	}
	// cout << g[1] << " " << g[2] << " " << g[3] << " " << g[4] << ln;
	ll dp[n+1];
	dp[1]=0;
	forsn(i,2,n+1){
		dp[i]=fby3[i];
		forsn(j,1,i){
			dp[i] -= dp[j]*f[i-j];
			dp[i] -= g[j]*fby3[i-j];
			dp[i] %= MOD;
		}
	}
	// cout << dp[1] << " " << dp[2] << " " << dp[3] << " " << dp[4] << ln;
	ll ans = dp[n];
	if(ans<0) ans+=MOD;
	cout << ans << ln;
}
 
int main()
{
	fast_cin();
	ansarr[2]=1;
	ansarr[3]=13;
	ansarr[4]=177;
	ansarr[5]=2669;
	ansarr[6]=44681;
	ansarr[7]=826101;
	ansarr[8]=16761769;
	ansarr[9]=370940293;
	ll t=1;
    cin >> t;
    forn(i,t) {
    	// cout << "Case #" << i+1 << ": ";
    	solve();
    }
    return 0;
}
