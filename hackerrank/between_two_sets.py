#!/usr/bin/python3

input().split(' ')
A = [int(x) for x in input().split(' ')]
B = [int(x) for x in input().split(' ')] 

between = [int(x) for x in range(101)[1:]]
between_len = 100

iA = 0
while iA < len(A) and between_len > 0:
    i = between_len - 1
    while i >= 0 and between_len > 0:
        if between[i] % A[iA] != 0:
            del between[i]
            between_len -= 1
        i -= 1
    iA += 1

iB = 0
while iB < len(B) and between_len > 0:
    i = between_len - 1
    while i >= 0 and between_len > 0:
        if B[iB] % between[i] != 0:
            del between[i]
            between_len -= 1
        i -= 1
    iB += 1

print(between_len)
