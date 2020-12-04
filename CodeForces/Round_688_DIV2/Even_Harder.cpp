#include<bits/stdc++.h>
using namespace std;
int _,n,dp[3005][3005],tot,a[3005],F[3005];

int main(){

    cin >> _;
    while (_--){
        cin >> n;
        for (int i=1;i<=n;i++) cin >> a[i];
        for (int i=1;i<=n+1;i++)
        for (int j=1;j<=n+1;j++) dp[i][j]=n+1;
        
        dp[1][1]=0;
        F[1]=0;
        
        for (int i=2;i<=n;i++) F[i]=n+1;
        for (int i=2;i<=n;i++){
            for (int j=1;j<=n;j++) F[j]=min(F[j],dp[j][i]);
            tot=0;
            for (int j=i-1;j;j--){
                if (j+a[j]>=i){
                    dp[i][j+a[j]+1]=min(dp[i][j+a[j]+1],F[j]+tot);
                    ++tot;
                }
            }
        }
        
        for (int j=1;j<=n;j++) F[j]=min(F[j],dp[j][n+1]);
        cout << F[n] << endl;
        
    }
    
    return 0;
}
