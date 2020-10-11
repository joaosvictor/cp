// https://www.codechef.com/LTIME88B
#include<bits/stdc++.h>

using namespace std ;

int main() {
	int t ;
	cin >> t ;
	while(t--){
		int N ;
		cin >> N ;

		int B[N];
		for( int i = 0 ; i < N ; i++ ){
			cin >> B[i] ;

		}
		int sum = 0 ;
		for( int i = 0 ; i < N ; i++ ){
			sum = sum + B[i];
		}
		if(sum < 0) {
			cout << "NO" << endl ;		
		}else if( sum >= 0 ){
			cout << "YES" << endl ;
		}
	}
	return 0 ;
}
