from math import floor

def rev(num):
    return float( str(num)[::-1] )

i, j, k = [int(x) for x in raw_input().split(' ')]

num_days = 0
for n in range(i, j+1):
    val = abs(n - rev(n))/k
    if val == floor(val):
        num_days += 1

print num_days
