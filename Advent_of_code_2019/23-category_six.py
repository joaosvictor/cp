import AOCUtils
from intcodeVM import VM
rawProgram = AOCUtils.loadInput(23)
memory = [int(i) for i in rawProgram.split(",")]

vms = [VM(memory) for _ in range(50)]
for i, vm in enumerate(vms):
    vm.run(i)

p1done = False

nat = None
seen = set()

queues = [[] for i in range(50)]
while True:
    idle = True

    for i, vm in enumerate(vms):
        if queues[i]:
            idle = False
            vm.run(queues[i])
            queues[i] = [] # Clear queue
        else:
            vm.run(-1)

       
        while vm.output:
            idle = False
            dest, x, y = vm.output[:3]
            vm.output = vm.output[3:]
            if dest == 255:
                if not p1done:
                    print("Part 1: {}".format(y))
                    p1done = True
                nat = (x, y) 
            else:
                queues[dest] += [x, y]
        vm.output = []

    
    if idle:
        queues[0] += nat
        if nat in seen:
            print("Part 2: {}".format(nat[1]))
            break
        seen.add(nat)

AOCUtils.printTimeTaken()
