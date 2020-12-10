#!/usr/bin/env python3
import re

# convert input
input = open('input.txt').read().split("\n\n")
for i in range(len(input)):
    input[i] = re.split("\s|\n", input[i])

passPorts = []

for i in range(len(input)):
    count = 0
    tempPassInfo = {}
    for info in input[i]:
        pair = info.split(":")
        tempPassInfo[pair[0]] = pair[1]
    passPorts.append(tempPassInfo)


def checkValidPassports(dictList):

    validPassports = 0
    for dictionary in dictList:
        if (len(dictionary.keys()) == 7 and "cid" not in dictionary.keys()) or (len(dictionary.keys()) == 8):
            validPassports += 1
    return validPassports


def checkValidPassportsV2(dictList):

    validPassports = 0
    for dictionary in dictList:
        if (len(dictionary.keys()) == 7 and "cid" not in dictionary.keys()) or (len(dictionary.keys()) == 8):
            byr = (len(dictionary["byr"])) and (1920 <= int(dictionary["byr"]) <= 2002)
            iyr = (len(dictionary["iyr"])) and (2010 <= int(dictionary["iyr"]) <= 2020)
            eyr = (len(dictionary["eyr"])) and (2020 <= int(dictionary["eyr"]) <= 2030)
            hgt = False
            if dictionary["hgt"][-1:-3:-1][::-1] == "cm":
                if 150 <= int(dictionary["hgt"][-3::-1][::-1]) <= 193:
                    hgt = True
            elif dictionary["hgt"][-1:-3:-1][::-1] == "in":
                if 59 <= int(dictionary["hgt"][-3::-1][::-1]) <= 76:
                    hgt = True
            hcl = True
            for character in dictionary["hcl"]:
                if character not in ["#", "a", "b", "c", "d", "e", "f", "0", "1", "2", "3", "4", "5", "6", "7", "8",
                                     "9"] or dictionary["hcl"][0] != "#":
                    hcl = False
                    break
            ecl = dictionary["ecl"] in ["amb", "blu", "brn", "gry", "grn", "hzl", "oth"]
            pid = len(dictionary["pid"]) == 9

            if byr and iyr and eyr and hgt and hcl and ecl and pid:
                validPassports += 1
    return validPassports

# run both parts
print("Answer to Part 1:")
print(checkValidPassports(passPorts))
print('')
print("Answer to Part 2:")
print(checkValidPassportsV2(passPorts))
