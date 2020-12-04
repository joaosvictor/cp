#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t --) {
		ll k; cin >> k;
		if(k & 1) {
			cout << -1 << "\n";
			continue;
		}
		vector <int> ans = {1};
		ll cur = 2, sum = 2;
		while(cur < k) {
			if(cur + 2 * sum + 2 <= k) {
				sum = 2 * sum + 2;
				ans.push_back(0);
			}
			else {
				cur += sum;
				sum = 2;
				ans.push_back(1);
			}
		}
		cout << (int) ans.size() << "\n";
		for(int x : ans) cout << x << " ";
		cout << "\n";
	}
 
	return 0;
}
