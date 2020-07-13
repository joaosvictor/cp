def c(n,r):
    a = 1
    for i in range(r):
        a *= (n-i)
        a %= mod
    return a*ifact[r]%mod
 
mod = pow(10,9)+7
inv = [0,1]
fact = [1,1]
ifact = [1,1]
for i in range(2,16):
    inv.append(inv[mod%i]*(mod-mod//i)%mod)
    fact.append(i*fact[-1]%mod)
    ifact.append(ifact[-1]*inv[i]%mod)
 
t = int(input())
for _ in range(t):
    ans = 0
    n = int(input())-5
    for o in range(12):
        m = n-o
        if (m<0 or m&1):
            continue
        ans += c(11,o)*c(m//2+15,15)
        ans %= mod
    print(ans)
