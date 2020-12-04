#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main(){

	ll t;
	cin>>t;
  
	while(t--){
  
		int n,m;
		cin>>n>>m;
		int f=n+m;
    
		set<int> a;
		for(int i=0;i<f;i++){
    
			int u;
			cin>>u;
			a.insert(u);
      
		}
		cout<<f-(int)a.size()<<endl;
   
	}
}
