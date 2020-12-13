#!/usr/bin/env python3
from itertools import count
from sympy.ntheory.modular import solve_congruence


with open('input.txt') as f:
    ls = [line.strip() for line in f.readlines()]

earliest = int(ls[0])
bus_times = [(-i, int(x)) for i, x in enumerate(ls[1].split(',')) if x != 'x']
i, busses = zip(*bus_times)

print('Answer to puzzle 1: ')
print(next((time - earliest)*bus
           for time in count(earliest) for bus in busses
           if time % bus == 0))

print('')

# learn sympy -> https://docs.sympy.org/latest/index.html
print('Answer to puzzle 2: ')
print(solve_congruence(*bus_times)[0])
