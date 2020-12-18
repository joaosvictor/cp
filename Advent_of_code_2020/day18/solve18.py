#!/usr/bin/env python3
import ast


with open('input.txt') as f:
    ls = [line.strip() for line in f.readlines()]

# https://www.geeksforgeeks.org/expression-evaluation/
def evaluate(code):
    root = ast.parse(code, mode='eval')
    for node in ast.walk(root):
        if type(node) is ast.BinOp:
            node.op = ast.Add() if type(node.op) is ast.Div else ast.Mult()
    return eval(compile(root, '<string>', 'eval'))


# Replace + with / to decrease binding
print('Answer to puzzle 1: ')
print(sum(
    evaluate(l.replace('+', '/')) for l in ls
))

# Replace * with + to increase binding
print('')
print('Answer to puzzle 2: ')
print(sum(
    evaluate(l.replace('+', '/').replace('*', '+')) for l in ls
))
