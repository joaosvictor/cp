#!/usr/bin/env python3

def move(current, right):

    removed = [right[current],
               right[right[current]],
               right[right[right[current]]]]
    right[current] = right[removed[-1]]
    destination = current
    while True:
        destination -= 1
        if destination == 0:
            destination = len(right)
        if destination not in removed:
            break
    right[removed[-1]] = right[destination]
    right[destination] = removed[0]
    return right[current]


def solve(cups, iterations):
    '''
     Poor man's linked list: Keep track of clockwise cups by label. This
     could be an array, but that actually makes lookups slower
    '''
    right = dict(zip(cups, cups[1:] + cups[:1]))
    current = cups[0]
    for i in range(iterations):
        current = move(current, right)
    return right


print('Answer to puzzle 1: ')
cups = list(map(int, '916438275'))
right = solve(cups, 100)
cup = 1
for i in range(8):
    cup = right[cup]
    print(cup, end='')
print()
print('')

print('Answer to puzzle 2: ')
cups += range(10, 1_000_001)
right = solve(cups, 10_000_000)
print(right[1] * right[right[1]])