r, r, d = map(int, input().split())
result = 0 
for i in range(l, r+1):
    if i % d == 0:
        result += 1

print(result)
