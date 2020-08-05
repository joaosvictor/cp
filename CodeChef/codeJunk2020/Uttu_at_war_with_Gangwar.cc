#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
#include <iomanip>
using namespace std;
#define pb push_back
#define ll long long int
# define pll pair<ll,ll>
int n,k;
ll a[200001];
vector<int> adj[200001];
ll x;
void dfs(int v, int p , int dep){
	//cout<<v<<" "<<dep<<"\n";
	//cout<<a[v]<<"\n";
	if(dep%2==1)x=x^a[v];
//	cout<<x<<"\n";
	for(int i=0;i<adj[v].size();i++){
		if(adj[v][i]==p)continue;
		dfs(adj[v][i],v,dep+1);
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int u,v;
	for(int i=0;i<n-1;i++){
		cin>>u>>v;
		--u,--v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	x=0;
	dfs(0,-1,0);
	//cout<<x<<"\n";
	if(x)
		cout<<"First";
	else
	cout<<"Second";
}
