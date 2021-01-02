#include <bits/stdc++.h>

typedef long long ll;
 
using namespace std;
const ll MAX=90000000000000;
const int mod = 1000000007;

int main(){
    
    int N;
    cin>>N;
    vector<pair<pair<ll,ll>,ll>>pr(N);
    
    ll sum_a=0;
    ll sum_t=0;
    int count=1;
    
    for(int i=0;i<N;i++){
        cin>>pr[i].first.first>>pr[i].first.second;
        pr[i].second=pr[i].first.first+pr[i].first.second+pr[i].first.first;
        
        sum_a+=pr[i].first.first;
        sum_t+=pr[i].first.first+pr[i].first.second;
    }
    
    sort(pr.begin(),pr.end(),[](pair<pair<ll,ll>,ll> a,pair<pair<ll,ll>,ll> b){
        return a.second>b.second;
    });
    
    ll sum_tt=0;
    for(int i=0;i<N;i++){
        sum_tt+=pr[i].first.first+pr[i].first.second;
        sum_a-=pr[i].first.first;
       
        if(sum_tt>sum_a){
            
            break;
        }
        count++;
    }
    
    cout<<count<<endl;
    

}
