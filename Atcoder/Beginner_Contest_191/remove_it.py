l1 = input().split()
l2 = input().split()
 
l3 = ""
for l in l2:
  if l != l1[1]:
    print(l + " ", end = "")
