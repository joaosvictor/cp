#include <bits/stdc++.h>
const int N = 1e6+5;
int T, n, L[N], R[N], m, a[N]; char s[N];

void dfs(int x)
{
    if(R[x]) --R[x], dfs(x+1);
    if(L[x]) --L[x], dfs(x-1);
    a[++m] = x;
}
int main()
{
    for(scanf("%d", &T); T--; )
    {
        scanf("%s", s+1), n = strlen(s+1);
        for(int i = 1, x = n; i <= n; ++i) if(s[i] == '0') ++R[x], ++x; else ++L[x], --x;
        m = 0, dfs(n); for(int i = m; i > 1; --i) putchar(a[i-1]-a[i] == 1?'0':'1'); puts("");
    }
    return 0;
}