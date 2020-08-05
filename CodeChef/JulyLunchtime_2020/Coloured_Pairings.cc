#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

struct stopwatch {
  clock_t t = clock();
  void restart() { t = clock(); }
  int elapsed() const { return (clock() - t) * 1000 / CLOCKS_PER_SEC; }
  void operator()(string s = "Time") const {
    cerr << s + ": " << elapsed() << " ms\n";
  }
};

mt19937 mt_engine(chrono::steady_clock::now().time_since_epoch().count());
template <class T> enable_if_t<is_integral_v<T>, T> rng(T l, T r) {
  return uniform_int_distribution<T>(l, r - 1)(mt_engine);
}
template <class T> enable_if_t<is_floating_point_v<T>, T> rng(T l, T r) {
  return uniform_real_distribution<T>(l, r)(mt_engine);
}

template <class T> struct disjoint_sparse_table {
  vector<vector<T>> t;
  disjoint_sparse_table(const vector<T>& v) : t(1, v) {
    for (int k = 1, n = v.size(); 1 << k < n; ++k) {
      t.push_back(v);
      for (int m = 1 << k; m < n; m += 1 << (k + 1)) {
        partial_sum(rend(v) - m, rend(v) - (m - (1 << k)),
                    rend(t[k]) - m, [](T a, T b) { return b * a; });
        partial_sum(begin(v) + m, begin(v) + min(m + (1 << k), n),
                    begin(t[k]) + m, multiplies<>());
      }
    }
  }
  T fold(int l, int r) const {
    assert(l < r);
    if (l == --r) return t[0][l];
    int k = __lg(l ^ r);
    return t[k][l] * t[k][r];
  }
};

struct node {
  long long sum = 0, mx = 0, lmx = 0, rmx = 0;
  node operator*(const node& b) const {
    node c;
    c.sum = sum + b.sum;
    c.mx = max({mx, b.mx, rmx + b.lmx});
    c.lmx = max(lmx, sum + b.lmx);
    c.rmx = max(b.rmx, rmx + b.sum);
    return c;
  }
};
node make_node(int x) {
  int mx = max(x, 0);
  return {x, mx, mx, mx};
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  auto f = [](auto&& a) {
    int n = size(a);
    vector<long long> dp(n + 1);
    for (int i = 0; i < n; ++i) {
      dp[i + 1] = max(dp[i], 0LL) + a[i];
    }
    return *max_element(begin(dp), end(dp));
  };
  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;
    stopwatch sw;
    vector<int> a(n), c(n);
    vector<vector<int>> idx(n);
    for (auto&& e : a) cin >> e;
    for (int i = 0; i < n; ++i) {
      cin >> c[i];
      --c[i];
      idx[c[i]].push_back(i);
    }
    constexpr int th = 600;
    vector<vector<long long>> pre(n);
    for (int x = 0; x < n; ++x) {
      if ((int)size(idx[x]) < th) continue;
      pre[x].resize(n);
      vector<node> _dst;
      for (int i : idx[x]) {
        _dst.push_back(make_node(a[i]));
      }
      disjoint_sparse_table dst(_dst);
      auto zip = [&](int i) {
        return lower_bound(begin(idx[x]), end(idx[x]), i) - begin(idx[x]);
      };
      for (int y = 0; y < n; ++y) {
        if (y == x) continue;
        if (empty(idx[y])) {
          pre[x][y] = dst.fold(0, size(idx[x])).mx;
          continue;
        }
        node e;
        if (idx[x][0] < idx[y][0]) {
          e = dst.fold(zip(0), zip(idx[y][0]));
        }
        e = e * make_node(a[idx[y][0]]);
        vector<int> zi(size(idx[y]));
        for (int t = 0; t < (int)size(idx[y]); ++t) {
          zi[t] = zip(idx[y][t]);
          if (t == 0) continue;
          if (zi[t - 1] < zi[t]) {
            e = e * dst.fold(zi[t - 1], zi[t]);
          }
          e = e * make_node(a[idx[y][t]]);
        }
        if (idx[y].back() < idx[x].back()) {
          e = e * dst.fold(zip(idx[y].back()), zip(n));
        }
        pre[x][y] = e.mx;
      }
    }
    while (q--) {
      int x, y;
      cin >> x >> y;
      --x, --y;
      if ((int)size(idx[y]) >= th) {
        swap(x, y);
      }
      if ((int)size(idx[x]) >= th) {
        cout << pre[x][y] << '\n';
      } else {
        auto itx = begin(idx[x]), ity = begin(idx[y]);
        vector<int> v;
        while (itx != end(idx[x]) or ity != end(idx[y])) {
          if (itx == end(idx[x]) or (ity != end(idx[y]) and *ity < *itx)) {
            v.push_back(a[*ity++]);
          } else {
            v.push_back(a[*itx++]);
          }
        }
        cout << f(v) << '\n';
      }
    }
    // sw();
  }
}
