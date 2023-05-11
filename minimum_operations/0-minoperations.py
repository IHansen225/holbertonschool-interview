#!/usr/bin/python3
"""
    Minimum Operations
"""


def minOperations(n):
    """
        Method that calculates the fewest number of operations
        needed to result in exactly n H characters in the file.
    """
    op = 0
    chrs = 1
    if n <= 1:
        return op
    while chrs < n:
        if n % chrs == 0:
            op += 2
            chrs += chrs
        else:
            op += 1
            chrs += chrs
    return op
