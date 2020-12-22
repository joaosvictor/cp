#!/usr/bin/env python3
from collections import defaultdict

data = [i[:-1] for i in open("input.txt", "r").readlines()]


def solve(lines):

    decks = []
    pt = 0
    while pt < len(lines):
        arr = []
        while pt < len(lines) and lines[pt]:
            arr.append(lines[pt])
            pt += 1
        pt += 1
        decks.append(list(map(int, arr[1:])))

    def part_1(d1, d2):
        while d1 and d2:
            a, *d1 = d1
            b, *d2 = d2
            if a < b:
                d2.extend([b, a])
            else:
                d1.extend([a, b])
        return d1 if d1 else d2

    # Possible optimizations that I may try later:
    #  - Use faster hash (the deck changes by 1-2 items every turn)
    #  - Change the list into a deque
    #  - Memoization
    
    def helper(d1, d2):
        seen = set()
        while d1 and d2:
            label = tuple(d1), tuple(d2)
            if label in seen:
                return 1, d1
            seen.add(label)
            a, *d1 = d1
            b, *d2 = d2
            if a <= len(d1) and b <= len(d2):
                if helper(d1[:a], d2[:b])[0] == 1:
                    d1.extend([a, b])
                else:
                    d2.extend([b, a])
            elif a < b:
                d2.extend([b, a])
            else:
                d1.extend([a, b])
        return (1, d1) if d1 else (0, d2)

    get_score = lambda deck: sum(i * v for i, v in enumerate(deck[::-1], 1))

    return get_score(part_1(*decks)), get_score(helper(*decks)[1])


part1, part2 = solve(data)
print('Answer to puzzle 1: ')
print(part1)
print('')
print('Answer to puzzle 2: ')
print(part2)