text = input()
data = []
for i in text:
  data.append(i)
 
for d in range(0,len(text)):
  if data[d] == "?":
    data[d] = "D"
ans = ''.join(data)
print(ans)
