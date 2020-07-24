import heapq
 
def solve():
    n = int(input())
    hp = 0
    ord_l = [[] for _ in range(n)]
    ord_r = [[] for _ in range(n)]
    bd_l, bd_r = 0, 0
    for _ in range(n):
        k, l, r = map(int, input().split())
        if k == n:
            hp += l
            continue
        if l == r:
            hp += l
            continue
 
        hp += min(l, r)
        if l > r:
            ord_l[k-1].append(l-r)
            bd_l = max(bd_l, k)
        else:
            ord_r[k].append(r-l)
            bd_r = max(bd_r, n-k)
 
    ord_l = ord_l[:bd_l][::-1]
    ord_r = ord_r[-bd_r:]
 
    left = []
    heapq.heapify(left)
    for i in range(bd_l):
        for x in ord_l[i]:
            heapq.heappush(left, -x)
        if left:
            hp += (heapq.heappop(left)*(-1))
    
    right = []
    heapq.heapify(right)
    for i in range(bd_r):
        for x in ord_r[i]:
            heapq.heappush(right, -x)
        if right:
            hp += (heapq.heappop(right)*(-1))
    print(hp)
 
 
def main():
    t = int(input())
    for _ in range(t):
        solve()
 
main()
