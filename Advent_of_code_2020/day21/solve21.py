#!/usr/bin/env python3
from collections import defaultdict

f = [i[:-1] for i in open("input.txt", "r").readlines()]


def solve(lines):

    cand = defaultdict(list)
    ing = defaultdict(int)
    for i in lines:
        a, b = i[:-1].split(" (contains ")
        for j in b.split(", "):
            cand[j].append(set(a.split()))
        for j in a.split():
            ing[j] += 1

    uncertain = set()
    used = set()
    known = {}
    for allergen in cand:
        bad = cand[allergen][0]
        for i in cand[allergen]:
            bad &= i
        uncertain |= bad
        if len(bad) == 1:
            known[allergen] = next(iter(bad))
            used.add(known[allergen])

    while len(cand) != len(known):
        for allergen in cand:
            if allergen not in known:
                bad = cand[allergen][0] - used
                for i in cand[allergen]:
                    bad &= i
                if len(bad) == 1:
                    known[allergen] = next(iter(bad))
                    used.add(known[allergen])

    p1 = sum(cnt for i, cnt in ing.items() if i not in uncertain)
    p2 = ",".join(j for i, j in sorted(known.items()))
    return p1, p2


part1, part2 = solve(f)
print('Answer to puzzle 1: ')
print(part1)
print('')
print('Answer to puzzle 2: ')
print(part2)
