import AOCUtils
from intcodeVM import VM
from collections import deque

def check(memory, x, y):
    vm = VM(memory)
    vm.run([x, y])
    return vm.output[-1]


rawProgram = AOCUtils.loadInput(19)
memory = [int(i) for i in rawProgram.split(",")]

total = 0
x0 = 0
for y in range(50):
    zeros, ones = 0, 0
    for x in range(x0, 50):
        if check(memory, x, y) == 1:
            if ones == 0: x0 = x
            ones += 1
        else:

            if ones > 0: 
                total += ones
                break
            else: 
                zeros += 1
                if zeros > 5: break

print("Part 1: {}".format(total))

result = None
x0 = 0
for y in range(100, 10000): 
    if result: break
    for x in range(x0, 10000):

        if check(memory, x, y) == 1:
            if check(memory, x+99, y-99) == 1: 
                result = 10000*x+(y-99) 
            x0 = x
            break

print("Part 2: {}".format(result))

AOCUtils.printTimeTaken()
