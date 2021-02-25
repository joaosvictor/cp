#!/usr/bin/env python3
import math

N=int(input())
A=list(map(int,input().split()))

min_a=min(A)
Yakusuu={}
 
for i in range(N):
  a=A[i]
  i=1
  yakusuu=[]
  while i*i<=a:
    if a%i==0:
      if i<=min_a:
        yakusuu.append(i)
      if i!=a//i and a//i<=min_a: 
        yakusuu.append(a//i)
    i+=1
  for t in yakusuu:
    if t in Yakusuu:
      Yakusuu[t]=math.gcd(Yakusuu[t],a)
    else:
      Yakusuu[t]=a
      
ans=0
Ans=list(set(list(Yakusuu.values())))
for x in Ans:
  if x<=min_a:
    ans+=1
print(ans)
