import math
 
def main():
    X, Y, R = map(float, input().split())
    big = 10000
 
    big_X = round(X*big)
    big_Y = round(Y*big)
    big_R = round(R*big)
    
    max_X = (big_X + big_R) // big
    min_X = (big_X - big_R) // big
    count = 0
    
    for x in range(min_X, max_X + 1):
        tmp = pow(big_R, 2) - pow((big_X - x*big), 2)
        if tmp >= 0:
            l = math.isqrt(tmp)
            Y_max = int((big_Y + l) // big)
            Y_min = int((big_Y - l - 1) // big)
            
            count += Y_max - Y_min
    else:
        print(count)
 
if __name__ == '__main__':
    main()
