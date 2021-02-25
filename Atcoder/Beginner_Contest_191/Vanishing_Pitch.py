l = input().split()
v = int(l[0])
t = int(l[1])
s = int(l[2])
d = int(l[3])
 
if (d < v * t) or (d > v * t and d > v * s):
  print("Yes")
else:
  print("No")
