n= int(input())
ans = list(map(int, input().split()))
c = 0
for i in range(n):
    if (i+1) % 2 != 0:
        if ans[i] % 2 != 0:
            c += 1
 
print(c)
