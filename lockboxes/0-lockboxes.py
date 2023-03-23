#!/usr/bin/python3
"""
    You have n number of locked boxes in front of you.
    Each box is numbered sequentially from 0 to n - 1
    and each box may contain keys to the other boxes.
    Write a method that determines if all the boxes can be opened.
"""

def canUnlockAll(boxes):
    """
        Check if all boxes can be unlocked
    """
    n = len(boxes)
    unlocked = [False] * n  # keep track of whether a box is unlocked or not
    unlocked[0] = True  # the first box is already unlocked
    stack = [0]  # start with the first box

    while stack:
        box = stack.pop()
        for key in boxes[box]:
            if key >= 0 and key < n and not unlocked[key]:
                unlocked[key] = True
                stack.append(key)

    return all(unlocked)
