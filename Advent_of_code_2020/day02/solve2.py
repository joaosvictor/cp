#!/usr/bin/env python3 

input = open('input.txt').readlines()
passwords = [line.strip() for line in input]


def validPasswords(passList):

    numValid = 0
    for policyPass in passList:
        policy,password = tuple(policyPass.split(": "))
        numPolicy,letterPolicy = tuple(policy.split(" "))
        minValue, maxValue = tuple(numPolicy.split("-"))

        count = 0
        for character in password:
            if character == letterPolicy:
                count+=1
        
        if count >= int(minValue) and count<=int(maxValue):
            numValid+=1

    return numValid

# run part 1
print("Answer to puzzle 1:")
print(validPasswords(passwords))


def validPasswords2(passList):

    numValid = 0
    for policyPass in passList:
        policy,password = tuple(policyPass.split(": "))
        numPolicy,letterPolicy = tuple(policy.split(" "))
        pos1, pos2 = tuple(numPolicy.split("-"))
        pos1 = int(pos1)-1
        pos2= int(pos2)-1

        if len(password) > pos2:
            if (letterPolicy==password[pos1] and letterPolicy!=password[pos2]) or (letterPolicy!=password[pos1] and letterPolicy==password[pos2]):
                numValid += 1

    return numValid

# run part 2
print('')
print("Answer to puzzle 2:")
print(validPasswords2(passwords))
