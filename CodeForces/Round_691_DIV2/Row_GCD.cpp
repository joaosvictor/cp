#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ll x,g=0,n,m,a1;
	cin>>n>>m>>a1;
	for(int i=1;i<n;i++)cin>>x,g=__gcd(g,abs(x-a1));
	for(int i=0;i<m;i++)cin>>x,cout<<__gcd(g,a1+x)<<" ";
	return 0;
}