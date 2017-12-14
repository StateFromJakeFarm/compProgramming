t1, t2, n = [int(x) for x in raw_input().split(' ')]

tn = 0
for i in range(n-2):
    tn = t1 + t2**2
    if i == n-3:
        print tn
        break

    t2, t1 = tn, t2
