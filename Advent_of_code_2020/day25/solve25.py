#!/usr/bin/env python3 

m = 20201227

def calc(s, p):
    answer = 0
    v = 1
    while v != p:
        answer += 1
        v = (s * v) % m

    return answer

def main():
    pt1 = int(input())
    pt2 = int(input())

    list1 = calc(7, pt1)
    list2 = calc(7, pt2)
    print('Answer to final puzzle')
    print(pow(pt2, list1, m), pow(pt1, list2, m))
    
main()