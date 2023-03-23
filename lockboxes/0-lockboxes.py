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
    opened = {0}
    changed = True
    while changed and len(opened) != len(boxes):
        changed = False
        for i in range(len(boxes)):
            if i in opened:
                for j in range(len(boxes[i])):
                    if boxes[i][j] not in opened:
                        opened.add(boxes[i][j])
                        changed = True
    return False if len(opened) != len(boxes) else True
