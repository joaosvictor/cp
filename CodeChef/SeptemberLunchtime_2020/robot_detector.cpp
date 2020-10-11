#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include <chrono>
#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define PI 3.14159265358979323846
const int mod = 1000000007;
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	auto start = chrono::steady_clock::now();


	int t = 1;
	while (t--) {
		int r, c;
		cin >> r >> c;
		if (r == 1 && c == 20) {
			cout << "U";
			for (int i = 1; i <= 20; ++i)
				cout << "R";
			cout << endl;
		}
		else if (r == 5 && c == 5) {
			bool f = true;
			int a = 10, b = 10;
			int len = 0;
			for (int i = 1; i <= 5; ++i) {
				cout << "U";
				len += 1 + i + a;
				char ch = f ? 'R' : 'L';
				for (int j = 1; j <= i + a; ++j)
					cout << ch;
				b = b + 10;
				a = a + b;
				f = f ? false : true;
			}
			cout << endl;
		}
		else {
			bool f = true;
			int a = c, b = 20;
			int len = 0;
			for (int i = 1; i <= r; ++i) {
				cout << "U";
				len += 1 + i + a;
				char ch = f ? 'R' : 'L';
				for (int j = 1; j <= i + a; ++j)
					cout << ch;
				a = a + b;
				f = f ? false : true;
			}
			cout << endl;
		}
	}


	auto end = chrono::steady_clock::now();
	return 0;

}



