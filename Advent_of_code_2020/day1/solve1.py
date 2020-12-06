#!/usr/bin/env python3 

input = open('input.txt').readlines()
expenses = [int(line.strip()) for line in input]

def findPair(numList):

    for valueA in numList:
        complementaryNum = 2020 - valueA
        if (complementaryNum in numList):
            return valueA * complementaryNum
    return -1

print('Answer to puzzle 1:')
print(findPair(expenses))

def findTriplet(numList):

    for valueA in numList:
        for valueB in numList:
            for valueC in numList:
                if (valueA + valueB + valueC == 2020):
                    return valueA * valueB * valueC
    return -1

print('')
print('Answer to puzzle 2:')
print(findTriplet(expenses))

