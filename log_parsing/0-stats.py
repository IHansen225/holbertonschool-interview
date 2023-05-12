#!/usr/bin/python3
"""
    module
"""
import sys


def print_dir(d):
    for key, value in d.items():
        if value != 0:
            print("{}: {}".format(key, value))


if __name__ == "__main__":
    total = 0
    stats = {
        200: 0,
        301: 0,
        400: 0,
        401: 0,
        403: 0,
        404: 0,
        405: 0,
        500: 0
        }
    try:
        empty_file = True
        while(1):
            lis = []
            empty = True
            for line in sys.stdin:
                empty, empty_file = False, False
                args = line.split(" ")
                if not int(args[-2]) in list(stats.keys()):
                    continue
                lis.append(int(args[-1]))
                stats[int(args[-2])] += 1
                if len(lis) == 10:
                    break
            if empty:
                break
            total += sum(lis)
            print("File size: {}".format(total))
            print_dir(stats)
        if empty_file:
            print("File size: 0")
    except KeyboardInterrupt as e:
        print("File size: {}".format(total))
        print_dir(stats)
        raise e
