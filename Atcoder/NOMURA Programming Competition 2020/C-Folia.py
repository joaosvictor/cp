n = int(input())
nums = list(map(int, input().split()))
 

if n == 0:
    if nums[0] == 1:
        print(1)
    else:
        print(-1)
    exit()
if n > 0 and nums[0] >= 1:
    print(-1)
    exit()
 

 
rest = sum(nums)
 
n_node = 1
ans = 1
for i in range(1, n+1):
    n_node = min(n_node * 2, rest)
    ans += n_node
 
    n_node -= nums[i]
    rest -= nums[i]
 

    if n_node < 0:
        print(-1)
        exit()
    if n_node == 0 and i < n:
        print(-1)
        exit()
 
print(ans)
