#pragma region include
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <limits>
#include <list>
#include <numeric>
#include <queue>
#include <stack>
#include <utility>
#include <array>
#include <random>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <assert.h>
using namespace std;
typedef long long ll;
#define dump(x) // // cerr << #x << " = " << (x) << " [" << __LINE__ << ":" << __FUNCTION__ << "] " << endl;
// vector
template < typename T >
ostream& operator<<(ostream& os, vector< T >& v) {
    os << "{";
    for (int i = 0; i < (int)v.size(); i++) {
        os << v[i] << (i < v.size() - 1 ? ", " : "");
    }
    os << "}";
    return os;
}
// pair
template < typename T, typename U >
ostream& operator<<(ostream& os, const pair< T, U >& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
// map
template < typename T, typename U >
ostream& operator<<(ostream& os, const map< T, U >& map_var) {
    os << "{";
    for (auto itr = map_var.begin(); itr != map_var.end(); itr++) {
        os << "(" << itr->first << ", " << itr->second << ")";
        itr++;
        if (itr != map_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}
// set 
template < typename T >
ostream& operator<<(ostream& os, const set< T >& set_var) {
    os << "{";
    for (auto itr = set_var.begin(); itr != set_var.end(); itr++) {
        os << *itr;
        ++itr;
        if (itr != set_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}

template < typename T >
ostream& operator<<(ostream& os, const multiset< T >& set_var) {
    os << "{";
    for (auto itr = set_var.begin(); itr != set_var.end(); itr++) {
        os << *itr;
        ++itr;
        if (itr != set_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}
#pragma endregion

void mebi(vector<ll> &f,int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 1<<n; j++) {
            if (j&(1<<i)) {
                f[j] += f[j^(1<<i)];
            }
        }
    }
}

int bitpopcount(ll n) {
    int res = 0;
    while (n) {
        if (n & 1) res++;
        n >>= 1;
    }
    return res;
}

int main() {
    int n,m;cin >> n >> m;
    vector<ll> dp(1<<n,0);
    constexpr int INF = 1e9 + 6;
    for (int i = 0; i < m; i++) {
        int a,b;cin >> a >> b;
        a--;b--;
        dp[(1<<a)|(1<<b)] += 1;
    }
    mebi(dp,n);
    for (int i = (1<<n)-1; i >= 1; i--) {
        int bpc = bitpopcount(i);
        if (bpc == 1) {
            dp[i] = 1;
        }
        else {
            if (dp[i] == (ll)bpc*(bpc-1)/2) {
                dp[i] = 1;
            }
            else {
                dp[i] = INF;
            }
        }
    }
    for (int i = 1; i < 1<<n; i++) {
        for (int j = i; j != 0; j=i&(j-1)) {
            dp[i] = min(dp[i],dp[j]+dp[i^j]);
        }
    }
    // cout << dp << endl;
    cout << dp[(1<<n)-1] << endl;
    return 0;
}
