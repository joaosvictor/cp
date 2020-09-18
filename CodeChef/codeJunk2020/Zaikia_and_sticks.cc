#include<bits/stdc++.h>

typedef long long int ll;
using namespace std;
int main()
{
	ll n; cin >> n;
	ll ar[n];
	for(ll i = 0; i < n; i++)
		cin >> ar[i];
		
	bool ok = 0;
	ll a = -1,b = -1,c = -1;
	
	sort(ar, ar+n);
	for(ll i = 0; i < n-2; i++)
	{
		if(ar[i] + ar[i+1] > ar[i+2])
		{
			a = ar[i];
			b = ar[i+1];
			c = ar[i+2];
		}
	}
	
	if(a != -1)
		cout << "YES\n" << c << " " << b << " " << a << "\n";
	else
		cout << "NO\n";
	return 0;
}

