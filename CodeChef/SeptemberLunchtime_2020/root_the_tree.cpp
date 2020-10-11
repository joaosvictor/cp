#include<bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    
   int t;
   cin>>t;
   while(t--){
      int n;
      cin>>n;
      int indegree[10001]={0};
      int outdegree[10001]={0};
      for(int i=0;i<n-1;i++){
         int u,v;
         cin>>u>>v;
         outdegree[u]++;
         indegree[v]++;
      }
      if(indegree[1]+outdegree[1]==n-1){
         if(indegree[1])
         cout<<indegree[1]-1<<endl;
         else cout<<"0\n";
      }
      else{
         int sum=0;
         for(int i=1;i<=n;i++){
            if(indegree[i]>1)sum+=indegree[i]-1;
         }
         cout<<sum<<endl;
      }

   }

    return 0;
}
