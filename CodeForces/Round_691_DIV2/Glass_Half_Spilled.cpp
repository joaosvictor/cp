#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
const int maxn=105,maxk=maxn*maxn;
int n,suma,sumb,tmp;
int a[maxn],b[maxn];
double f[maxn][maxk],ans[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&b[i],&a[i]),tmp+=b[i],suma+=a[i];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=tmp;j++)
			f[i][j]=-1000000000000.0;
	f[0][0]=0;
	for(int i=1;i<=n;i++){
		sumb+=b[i];
		for(int j=i;j>=1;j--)
			for(int k=sumb;k>=b[i];k--)
				f[j][k]=max(f[j][k],f[j-1][k-b[i]]+a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=sumb;j++)
			ans[i]=max(ans[i],min(j*1.0,suma/2.0+f[i][j]/2.0));
		printf("%.10lf%c",ans[i],i==n? '\n':' ');
	}
	return 0;
}