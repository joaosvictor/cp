#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,x;
    string s;
    cin>>n>>x;
    cin>>s;
    for(ll i=0;i<n;i++)
    {
        if(s[i]=='x')
        {
            if(x!=0)
            {
             x--;   
            }
        }
        else
        {
            x++;
        }
    }
    cout<<x;
}
