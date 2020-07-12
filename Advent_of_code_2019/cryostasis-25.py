import AOCUtils
from intcodeVM import VM
from itertools import combinations
from collections import deque

def playGame(memory):
    vm = VM(memory)
    vm.run()
    print("".join([chr(c) for c in vm.output]))
    while not vm.halted:
        vm.output = []
        vm.run(input()+"\n")
        print("".join([chr(c) for c in vm.output]))
    exit()

def oppositeDoor(direction):
    opp = {"north": "south", "south": "north", "east": "west", "west": "east"}
    return opp[direction]


rawProgram = AOCUtils.loadInput(25)
memory = [int(i) for i in rawProgram.split(",")]


blacklist = set(["infinite loop", "molten lava", "giant electromagnet", "photons", "escape pod"])

vm = VM(memory)
vm.run()


finalState = None
maxItemsFound = 0

# BFS through all rooms, storing (room, inventory) visited states
visited = set()
queue = deque([(set(), [], vm)])
while queue:
    inventory, path, vm = queue.popleft()

    
    text = "".join([chr(c) for c in vm.output])
    vm.output = []

    room = text.split("==")[1].strip()


    visKey = (room, tuple(sorted(inventory)))
    if visKey in visited: continue
    visited.add(visKey)

    doors, items = [], []
    doorsStart = text.find("Doors here lead:")
    itemsStart = text.find("Items here:")
    if doorsStart != -1:
        doors = [line[2:] for line in text[doorsStart:itemsStart].split("\n") if line.startswith("-")]
    if itemsStart != -1:
        items = [line[2:] for line in text[itemsStart:].split("\n") if line.startswith("-")]

    # Pick up all items in the room
    for item in items:
        if item in blacklist: continue # But ignore the game-ending ones
        path.append("take " + item)
        vm.run("take " + item + "\n")
        inventory.add(item)


    visKey = (room, tuple(sorted(inventory)))
    visited.add(visKey)

    maxItemsFound = max(maxItemsFound, len(inventory))
    if len(inventory) < maxItemsFound: continue

    if room == "Security Checkpoint":
        # Get step to reach floor
        floorDirection = doors[0] if doors[0] != oppositeDoor(path[-1]) else doors[1]
        finalState = (vm, list(inventory), floorDirection)
        continue

    for door in doors:
        newVM = vm.copy()
        newVM.run(door+"\n")

        queue.append((set(inventory), path+[door], newVM))

vm, allItems, floorDirection = finalState
vm.run("\n".join(["drop "+item for item in allItems])+"\n") # Drop all items

# Generate all possible item combinations by increasing length
itemCombinations = []
for n in range(len(allItems)):
    itemCombinations += list(combinations(allItems, n))

# Bruteforce the pressure floor by trying all of the combinations 
inventory = set()
tooHeavy = []
for attemptItems in itemCombinations:
    # print("Trying items: {}".format(list(attemptItems)))

    # If inventory is a superset of any of tooHeavy, then it's also going to be too heavy
    if any([set(s).issubset(set(attemptItems)) for s in tooHeavy]): continue

    # Drop all items that aren't in attemptItems
    toDrop = [item for item in inventory if item not in attemptItems]
    vm.run("\n".join(["drop "+item for item in toDrop])+"\n")
    inventory = inventory.difference(set(toDrop))

    # Pick up all from attemptItems that aren't yet in inventory
    toPick = [item for item in attemptItems if item not in inventory]
    vm.run("\n".join(["take "+item for item in toPick])+"\n")
    inventory = inventory.union(set(toPick))

    # Activate floor
    vm.run(floorDirection+"\n")

    text = "".join([chr(c) for c in vm.output])
    vm.output = []

    # Verify result
    if text.find("Alert!") == -1:
        # print(text.split("\n\n")[-1].strip())
        print("Part 1: {}".format(text.split()[-8]))
        done = True
        break
    elif text.find("lighter") != -1: # Too heavy, add as invalid subset
        tooHeavy.append(attemptItems)

AOCUtils.printTimeTaken()
