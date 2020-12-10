#!/usr/bin/env python3 

def main():

    f = open('input.txt', 'r')
    adapters = [int(line.strip()) for line in f.readlines() if line.strip()]
    adapters.sort()
    adapters = [0] + adapters + [adapters[-1] + 3]
    last = 0
    a, b = 0, 0

    for x in adapters:
        assert x - last <= 3
        if x - last == 1:
            a += 1
        elif x - last == 3:
            b += 1
        last = x 
    print("Answer to part 1:")     
    #print(a, b, a * b)
    print(a * b) # -> 75 * 32
            

    # using dynamic programming 
    dp = [1]
    for i in range(1, len(adapters)):
        ans = 0
        for j in range(i):
            if adapters[j] + 3 >= adapters[i]:
                ans += dp[j]
        dp.append(ans)

    print('')    
    print("Answer to part 2:") 
    print(dp[-1])

if __name__ == '__main__':
    main()

