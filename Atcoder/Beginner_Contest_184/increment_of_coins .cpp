#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
 
ld f( ld a , ld b , ld c , ld*** dp  )
{
    if( a== 100 || b== 100 || c == 100 )
        return 0;
 
    if( dp[ll(a) ][ll(b)][ll(c)]  != -1 )
    {
        return dp[ll(a) ][ll(b)][ll(c)];
    }
 
    ld ans = (  a/(a+b+c) * ( f(a+1,b,c,dp) + 1  ) ) + ( b/(a+b+c) * ( f(a,b+1,c,dp) +1) ) + ( c/(a+b+c) *( f(a,b,c+1,dp)+ 1 )   );
    dp[ll(a) ][ll(b)][ll(c)]= ans;
    return ans;
}
 
int main()
{
    ld a , b, c;
    cin>>a>>b>>c;
 
    ld*** dp = new ld**[101 ];
    for(int i=0;i<=100 ;i++)
    {
        dp[i] = new ld*[101];
        for(int j=0;j<=100;j++)
        {
            dp[i][j] = new ld[101] ;
            for(int k=0;k<= 100 ;k++)
            {
                dp[i][j][k] = -1;
            }
        }
    }
    printf( "%.15Lf" ,  f( a , b,c , dp) );
}
