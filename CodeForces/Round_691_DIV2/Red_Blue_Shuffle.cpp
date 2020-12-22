#import<bits/stdc++.h>
using namespace std;

int i,n,x,y,t;
string a,b;

main()
{
	for(cin>>t;t--;)
	{
		cin>>n>>a>>b;
		for(i=x=y=0;i<n;i++)
		{
			if(a[i]>b[i])x++;
			if(a[i]<b[i])y++;
		}
		if(x>y)cout<<"RED"<<endl;
		else if(x<y)cout<<"BLUE"<<endl;
		else cout<<"EQUAL"<<endl;
	}
}
