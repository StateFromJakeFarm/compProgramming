T = int(raw_input())

for t in range(T):
    N = int(raw_input())
    A = [int(x) for x in raw_input().split(' ')]

    maxSeq = 0
    maxElm = -10**4 - 1
    for i in range(N):
        maxElm = max(maxElm, A[i])

        if A[i] > 0:
            maxSeq += A[i]

    if maxSeq == 0:
        maxSeq = maxElm

    for i in range(1, N):
        A[i] = max(A[i] + A[i-1], A[i])

    maxArray = max(A)

    print maxArray, maxSeq
