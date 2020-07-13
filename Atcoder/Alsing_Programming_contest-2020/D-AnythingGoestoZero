import sys
def input(): return sys.stdin.readline().strip()
 
n=int(input())
xs=input()
xj=xs.count("1")
 
x=int(xs,2)
xip=x%(xj+1)
if xj!=1:
    xim=x%(xj-1)
 
for i in range(n-1,-1,-1):
    if xs[n-1-i]=="0":
        pxi=xj+1
        i2=pow(2,i,pxi)
        xi=(xip+i2)%pxi
    elif xj==1:
        print(0)
        continue
    else:
        pxi=xj-1
        i2=pow(2,i,pxi)
        xi=(xim-i2)%pxi
    xi=xi%pxi
    if xi==0:
        print(1)
        continue
    icnt=1
    while xi>0:
        icnt+=1
        xi=xi%(bin(xi).count("1"))
    print(icnt)
