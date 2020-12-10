#!/usr/bin/env python3
import numpy as np

# convert the input into an array
input = open('input.txt').readlines()
for i in range(len(input)):
    input[i] = list(input[i].strip())
    inputMap = np.array(input, dtype=object)


def findTrees(treeMap):

    numTrees = 0
    width = treeMap.shape[1]
    depth = treeMap.shape[0]
    horizontalPos = 0

    for verticalPos in range(depth):
        if verticalPos > 0:
            horizontalPos += 3
            if horizontalPos >= width:
                horizontalPos = horizontalPos - width
            if treeMap[verticalPos, horizontalPos] == "#":
                numTrees += 1
    return numTrees


# run part 1
print("Answer to part 1:")
print(findTrees(inputMap))


def findTreesv2(treeMap, rightMov, downMov):

    numTrees = 0
    width = treeMap.shape[1]
    depth = treeMap.shape[0]
    horizontalPos = 0
    verticalPos = 0

    while verticalPos < depth:
        if horizontalPos >= width:
            horizontalPos = horizontalPos - width
        if treeMap[verticalPos, horizontalPos] == "#":
            numTrees += 1
        verticalPos += downMov
        horizontalPos += rightMov
    return numTrees


# run part 2
#print("----------")
print('')
print("Answer to part 2:")
product = findTreesv2(inputMap, 1, 1) * findTreesv2(inputMap, 3, 1) * findTreesv2(inputMap, 5, 1) * findTreesv2(inputMap, 7, 1) * findTreesv2(inputMap, 1, 2)
print(product)
