'''from collections import deque
import datetime
import math
import os
import random
import re
import sys
#n=list(map(int, input().split()))
#n=map(int, input().split())


def main():
	l,r,d=map(int,input().split())
	ans=0
    for i in range(l,r+1):
        if i%d== 0 :
			ans+=1
	print(ans)
main()
'''
import AOCUtils
from collections import deque

class Tunnels:
    def __init__(self, tunnels):
        self.tunnels = tunnels
        self.size = (len(tunnels), len(tunnels[0]))
        self.bots = []
        self.keys = dict()
        
        for x in range(len(tunnels)):
            for y in range(len(tunnels[0])):
                if tunnels[x][y] == "@":
                    self.keys[len(self.bots)] = (x, y)
                    self.bots.append((x, y))
                elif self.__isKey(tunnels[x][y]):
                    self.keys[tunnels[x][y]] = (x, y)

        self.keysToKeys = self.__getKeysToKeysDistance()

    def __isDoor(self, tile): return "A" <= tile <= "Z"
    def __isKey(self, tile): return "a" <= tile <= "z"

    def __getKeysToKeysDistance(self):
     
        keysToKeys = {k: dict() for k in self.keys}
        for keyA, posKeyA in self.keys.items():
            queue = deque([(posKeyA, 0, [])])
            visited = set()

            while queue:
                cur, dist, doors = queue.popleft()
                curTile = self.tunnels[cur[0]][cur[1]]

                if cur in visited: continue
                visited.add(cur)

                newDoors = doors[:]
                if self.__isDoor(curTile):
                    newDoors.append(curTile)

                keyB = curTile
                if keyB != keyA and self.__isKey(keyB):
                    keysToKeys[keyA][keyB] = (dist, newDoors)
                    keysToKeys[keyB][keyA] = (dist, newDoors)

                for m in [(0, -1), (-1, 0), (0, 1), (1, 0)]:
                    step = (cur[0]+m[0], cur[1]+m[1])
                    if self.tunnels[step[0]][step[1]] != "#":
                        queue.append((step, dist+1, newDoors))

        return keysToKeys

    def distanceToAllKeys(self):
        memo = dict() 

        def exploreRecursive(bots, inventory):
            memoKey = (tuple(sorted(bots)), tuple(sorted(inventory)))
            if memoKey in memo: return memo[memoKey]
            distances = []
            for botID, botPos in enumerate(bots):
                botTile = self.tunnels[botPos[0]][botPos[1]]
                if botTile == "@": botTile = botID 

                for key, (dist, doors) in self.keysToKeys[botTile].items():
                    # If not a key but a bot, ignore it
                    if type(key) is int: continue

                    # If key is already taken, ignore it
                    if key in inventory: continue

                    # If there are locked doors between bot and key, it can't be reached
                    if not set([d.lower() for d in doors]).issubset(inventory): continue

                    # Move bot to key
                    newBots = bots[:]
                    newBots[botID] = self.keys[key]

                    # Add key to inventory
                    newInventory = inventory | set(key)

                    # Add to possible paths (recurse)
                    distances.append(dist + exploreRecursive(newBots, newInventory))

            minDistance = min(distances) if distances else 0

            memo[memoKey] = minDistance
            return minDistance

        return exploreRecursive(self.bots, set())


rawTunnels = [list(s) for s in AOCUtils.loadInput(18)]

tunnels = Tunnels(rawTunnels)
print("Part 1: {}".format(tunnels.distanceToAllKeys()))

pos = tunnels.bots[0]
for w in [(-1, 0), (0, 0), (1, 0), (0, -1), (0, 1)]:
    rawTunnels[pos[0]+w[0]][pos[1]+w[1]] = "#"
for b in [(-1, -1), (-1, 1), (1, -1), (1, 1)]:
    rawTunnels[pos[0]+b[0]][pos[1]+b[1]] = "@"

tunnels = Tunnels(rawTunnels)
print("Part 2: {}".format(tunnels.distanceToAllKeys()))

AOCUtils.printTimeTaken()
