#include <iostream>
#include <vector>
 
using namespace std;
 
void solve() {
	int n;
	cin >> n;
	vector<vector<int>> m(n, vector<int>(n));
	vector<int> left(10, n), right(10, -1), top(10, n), down(10, -1);
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < n; ++j) {
			char c;
			cin >> c;
			m[i][j] = c - '0';
 
			left [m[i][j]] = min(left [m[i][j]], j);
			right[m[i][j]] = max(right[m[i][j]], j);
			top  [m[i][j]] = min(top  [m[i][j]], i);
			down [m[i][j]] = max(down [m[i][j]], i);
		}
 
	vector<int> ans(10, 0);
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < n; ++j) {
			ans[m[i][j]] = max(ans[m[i][j]], max(i - top[m[i][j]], down[m[i][j]] - i) * max(j - 0, n - 1 - j));
			ans[m[i][j]] = max(ans[m[i][j]], max(j - left[m[i][j]], right[m[i][j]] - j) * max(i - 0, n - 1 - i));
		}
 
	for (auto& x : ans) cout << x << ' ';
	cout << '\n';
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
 
	return 0;
}
