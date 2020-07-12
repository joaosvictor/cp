import AOCUtils

def makeFuel(recipes, fuelAmt):
    need = {"FUEL": fuelAmt}
    have = dict()
    while any([n != "ORE" for n in need.keys()]):
        for k in [n for n in need.keys() if n != "ORE"]:
            resultAmt, inputs = recipes[k]

            div = need[k]//resultAmt
            mod = need[k]%resultAmt           
            need.pop(k)      
            if mod != 0:
                div += 1
                have[k] = resultAmt - mod

            for inpAmt, inp in inputs:
                if inp not in have: have[inp] = 0
                if inp not in need: need[inp] = 0

                produced = div*inpAmt
                need[inp] -= have[inp] - produced 
                have[inp] = 0 

    return need["ORE"]

rawRecipes = AOCUtils.loadInput(14)

recipes = dict()
for recipe in rawRecipes:
    rawInputs, rawResult = recipe.split(" => ")
    resultAmt, result = rawResult.split()

    inputs = []
    for rawInput in rawInputs.split(", "):
        inpAmt, inp = rawInput.split()
        inputs.append((int(inpAmt), inp))
    recipes[result] = (int(resultAmt), inputs)

print("Part 1: {}".format(makeFuel(recipes, 1)))

#BS
lo, hi = 1, 10**9
while hi > lo+1:
    mid = (hi+lo)//2
    if makeFuel(recipes, mid) > 10**12:
        hi = mid
    else:
        lo = mid

print("Part 2: {}".format(lo))

AOCUtils.printTimeTaken()
