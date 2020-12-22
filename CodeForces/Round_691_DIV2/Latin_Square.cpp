
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
 
using std::swap;
 
typedef void (*TRANS)();
 
const int N=1003;
int n;
int d0=0,d1=1,d2=2;
int o0=0,o1=0,o2=0;
void up()
{
	o0+=n-1;
	o0%=n;
}
void down()
{
	o0++;
	o0%=n;
}
void left()
{
	o1+=n-1;
	o1%=n;
}
void right()
{
	o1++;
	o1%=n;
}
void xt()
{
	swap(d0,d2);
	swap(o0,o2);
}
void yt()
{
	swap(d1,d2);
	swap(o1,o2);
}
int val[N*N][3];
TRANS trans[256];
int main()
{
	trans['U']=up; trans['D']=down;
	trans['L']=left; trans['R']=right;
	trans['I']=yt; trans['C']=xt;
	int _t; scanf("%d",&_t);
	while (_t--)
	{
		d0=0,d1=1,d2=2;
		o0=0,o1=0,o2=0;
		int m; scanf("%d%d",&n,&m);
		int p=0;
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
			{
				int a;
				scanf("%d",&a);
				val[p][0]=i; val[p][1]=j; val[p][2]=a-1;
				p++;
			}
		getchar();
		for (int i=0;i<m;i++)
			trans[getchar()]();
		static int ans[N][N];
		for (int i=0;i<p;i++)
			ans[(val[i][d0]+o0)%n][(val[i][d1]+o1)%n]=(val[i][d2]+o2)%n;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++) printf("%d ",ans[i][j]+1);
			printf("\n");
		}
	}
	return 0;
}
