#!/usr/bin/env python3 

def decode(s):

    s = s.replace('F', '0')
    s = s.replace('B', '1')
    s = s.replace('L', '0')
    s = s.replace('R', '1')
    return int(s, 2)


with open('input.txt') as f:
    ids = [decode(l) for l in f]

# run both parts
print('Answer to Part 1:')
print(max(ids))

print('')

all_ids = set(range(min(ids), max(ids))) # part 2 
print('Answer to Part 2:')
print(set(all_ids) - set(ids))
