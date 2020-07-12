import AOCUtils
from intcodeVM import VM

def runSpringScript(memory, script):
    vm = VM(memory)
    vm.run("\n".join(script)+"\n")
    return vm.output[-1]



rawProgram = AOCUtils.loadInput(21)
memory = [int(i) for i in rawProgram.split(",")]

script1 = [
"OR A T",   # T = A
"AND B T",  # T = A & B
"AND C T",  # T = A & B & C
"NOT T J",  # J = !(A & B & C)
"AND D J",  # J = !(A & B & C) & D
"WALK"
]

print("Part 1: {}".format(runSpringScript(memory, script1)))



script2 = [
"OR A T",   # T = A
"AND B T",  # T = A & B
"AND C T",  # T = A & B & C
"NOT T T",  # T = !(A & B & C)
"OR E J",   # J = E
"OR H J",   # J = E | H
"AND T J",  # J = !(A & B & C) & (E | H)
"AND D J",  # J = !(A & B & C) & (E | H) & D
"RUN"]

print("Part 2: {}".format(runSpringScript(memory, script2)))

AOCUtils.printTimeTaken()
