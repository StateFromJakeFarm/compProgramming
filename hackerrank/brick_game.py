t = int(input())
for _ in range(t):
    n = input()
    # Store reversed version of array because we consider elements in the
    # stack from the bottom-up
    arr = [int(x) for x in reversed(input().split(' '))]

    # Record the sum of all elements up to this position (total score available)
    # in the remainder of the stack
    sum_arr = [sum(arr[:i+1]) for i in range(len(arr))]

    D = []
    for i in range(len(arr)):
        if i < 3:
            # If <= 3 elements left, best move is always to take all of them
            D.append(sum_arr[i])
        else:
            # Best move is that which maximizes what we're left with after our
            # opponent takes their share of the remainder of the stack
            D.append(max(
                sum_arr[i] - D[i-1], # We take top element
                sum_arr[i] - D[i-2], # We take top 2 elements
                sum_arr[i] - D[i-3]  # We take top 3 elements
            ))

    print(D[-1])
