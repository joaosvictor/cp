#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(), a.end()
#define rrng(a) a.rbegin(), a.rend()
using ll = long long;
using P = pair<int, int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using VP = vector<P>;
using VS = vector<string>;
using VC = vector<char>;
#define MOD 1000000007
const int INF = 1e9 + 10;          // int max > 2*10^9
const long long INFL = 2e18 + 10;  // ll max > 9*10^18
 
template <class T, class C>
bool chmax(T& a, C b) {
    if (a <= b) {
        a = b;
        return true;
    }
    return false;
}
template <class T, class C>
bool chmin(T& a, C b) {
    if (a >= b) {
        a = b;
        return true;
    }
    return false;
}
 
template <class T>
T sum(const vector<T>& v) {
    T res = 0;
    for (size_t i = 0; i < v.size(); ++i) res += v[i];
    return res;
}
 
void print() { cout << endl; }
 
template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail) != 0) cout << " ";
    print(forward<Tail>(tail)...);
}
 
template <class T>
void print(vector<T>& vec) {
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << " ";
    }
    cout << endl;
}
 
template <class T>
void print(vector<vector<T>>& df) {
    for (auto& vec : df) {
        print(vec);
    }
}
 
#pragma endregion Region_1
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    std::cout << std::setprecision(15);

    int n, t;
    cin >> n >> t;
    VI a(n / 2);
    VI b;
    rep(i, n / 2) {
        cin >> a[i];
    }
    srep(i, n / 2, n) {
        int x;
        cin >> x;
        b.push_back(x);
    }
    VL sum1;
    rep(i, 1 << a.size()) {
        ll val = 0;
        rep(j, a.size()) {
            if ((~i) >> j & 1) continue;
            val += a[j];
        }
        sum1.push_back(val);
    }
    sort(rng(sum1));
    ll ans = 0;
    rep(i, 1 << b.size()) {
        ll val = 0;
        rep(j, b.size()) {
            if ((~i) >> j & 1) continue;
            val += b[j];
        }
        if (val > t) continue;
        int idx = upper_bound(rng(sum1), t - val) - sum1.begin();
        idx--;
        chmax(ans, val + sum1[idx]);
    }
    print(ans);
 
    return 0;
}
