n = int(input())
rates = [1,1,3,6]
cnt = [0]*10001
def g(x,y,z):
    return x**2 + y**2 + z**2 + x*y + x*z + y*z 
for x in range(1,101):
    for y in range(x,101):
        for z in range(y,101):
            rate = rates[len(set([x,y,z]))]
            gv = g(x,y,z)
            if gv < 10001:
                cnt[gv]+=rate
for i in range(1,n+1):
    print(cnt[i])
