#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
const int MOD = 1000000007;
 
int main() {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(0); 
  
  int tc; cin >> tc;
  while(tc--) {
    int n; cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i=0; i<n-1; i++) {
      int u, v; cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    
    int res = 0;
    
    function<int(int,int,int)> dfs = [&](int u, int p, int d) {
      if(adj[u].size() == 1 && p != 0) {
        return d;
      }
 
      vector<int> t;
      for(int v : adj[u]) {
        if(v == p) continue;
        int dd = dfs(v, u, d+1);
        t.push_back(dd);
      }
      
      sort(t.begin(), t.end());
      if(p == 0) {
        for(int i=0; i<(int)t.size()-1; i++) {
          res = max(res, t[i]-d+1);
        }
        return t.back();
      }
      else {
        for(int i=1; i<(int)t.size(); i++) {
          res = max(res, t[i]-d+1);
        }
        return t[0];
      }
    };
    
    res = max(res, dfs(1, 0, 0));
    cout << res << '\n';
  };
 
  return 0;
}
