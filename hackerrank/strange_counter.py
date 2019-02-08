t = int(input())

p = 0
upper_bound = 0
while upper_bound < t:
    upper_bound = 3 * (2**(p+1) - 1)
    p += 1
p -= 1

this_dist = 3*(2**p)
time_covered = 3*(2**p - 1)

print(this_dist - (t - (time_covered+1)))
