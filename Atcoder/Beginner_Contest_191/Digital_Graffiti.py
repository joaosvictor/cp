h, w = map(int, input().split())
s = [list(input()) for _ in range(h)]
ans = 0
 
for i in range(h-1):
    for j in range(w-1):
        flag1 = 1 if s[i][j] == '#' else 0
        flag2 = 1 if s[i][j+1] == '#' else 0
        flag3 = 1 if s[i+1][j] == '#' else 0
        flag4 = 1 if s[i+1][j+1] == '#' else 0
        
        med = flag1 + flag2 + flag3 + flag4
        
        if med == 1 or med == 3:
            ans += 1
