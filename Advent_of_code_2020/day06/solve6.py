#!/usr/bin/env python3
import operator 
import functools

with open('input.txt') as f:
    groups = [[set(ll) for ll in l.split('\n')] for l in f.read().split('\n\n')]

print("Answer to Part 1:")
print(sum([len(functools.reduce(operator.or_, g)) for g in groups]))
print('')
print("Answer to Part 2:")
print(sum([len(functools.reduce(operator.and_, g)) for g in groups]))



