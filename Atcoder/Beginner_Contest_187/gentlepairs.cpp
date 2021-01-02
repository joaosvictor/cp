#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define ar array

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	ar<double, 2> a[n];
	for (int i=0; i<n; i++) cin >> a[i][0] >> a[i][1];
	int res=0;
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			double g=(a[j][1]-a[i][1])/(a[j][0]-a[i][0]);
			if (abs(g)<=1) res++;
		}
	}
	cout << res;
	return 0;
}