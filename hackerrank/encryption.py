#!/usr/bin/python3

from math import sqrt, ceil, floor

s = input().replace(' ', '')
col_len = int(floor(sqrt(len(s))))
row_len = int(ceil(sqrt(len(s))))

# Area of grid must be <= len(s)
if col_len * row_len < len(s):
    col_len += 1

# Print transpose
for c in range(row_len):
    for r in range(col_len):
        try:
            print(s[c + r*row_len], end='')
        except IndexError:
            break

    print(' ', end='')
print()
