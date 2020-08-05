#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "debug.h"
#define input                         \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#else
#define debug(...) 4
#define input 4
#endif

using ll = long long;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;

#define int long long
int32_t main() {
    input;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
               
    int t;
    t = 1;
    // cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        ll a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        auto f = [&](ll mid) {
            ll ans = 0;
            for(int i = 0; i < n; i++) {
                if(k == 1)
                    ans += 1LL * abs(a[i] - mid);
                if(k == 2)
                    ans += 1LL * (abs(a[i] - mid) * abs(a[i] - mid));
                if(k == 3)
                    ans += 1LL * (abs(a[i] - mid) * abs(a[i] - mid) * abs(a[i] - mid));
            }
            return ans;
        };
       
        int lo = 0, hi = 1e5;
        while(lo + 5 < hi) {
            int mid = (lo + hi) >> 1;
            if(f(mid) < f(mid+1)) {
                hi = mid;
            }
            else {
                lo = mid+1;
            }
        }

        ll ans = LLONG_MAX;
        debug(lo, hi);
        for(int i = lo; i <= hi; i++) {
            debug(f(i));
            ans = min(ans, f(i));
        }
        debug(ans);
        for(int i = lo; i <= hi; i++) {
            if(f(i) == ans) {
                cout << i << "\n";
                break;
            }
        }
    }
    
}
