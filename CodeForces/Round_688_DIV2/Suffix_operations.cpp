#include<bits/stdc++.h>
using namespace std;
long long a[200001],s[200001];

int main(){

	int T;
	cin>>T;
	while(T--){
	
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
    
		s[0]=0;
		for(int i=1;i<n;i++)
		s[i]=abs(a[i]-a[i-1])+s[i-1];
		long long ans=s[n-1]-abs(a[1]-a[0]);
    
		for(int i=1;i<n-1;i++)
    
		ans = min(ans,abs(a[i+1]-a[i-1])+s[i-1]+s[n-1]-s[i+1]);
		ans = min(ans,s[n-2]);
		cout << ans <<endl;	
	}
 } 
