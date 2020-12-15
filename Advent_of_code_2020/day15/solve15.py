#!/usr/bin/env python3

input = [17,1,3,16,19,0]
TARGET1 = 2020
TARGET2 = 30_000_000

def build_hash(input):
    ret = {}
    for ix, i in enumerate(input[:-1]):
        ret[i] = ix+1
    return ret

hash = build_hash(input)
last_spoken = input[-1]

for i in range(len(input), TARGET2):
    if i == TARGET1:
        print("Answer to puzzle 1:")
        print(last_spoken)
    if last_spoken in hash:
        next_to_speak = i - hash[last_spoken]
    else:
        next_to_speak = 0
    hash[last_spoken] = i
    last_spoken = next_to_speak

print('')
print("Answer to puzzle 2:")    
print(last_spoken)