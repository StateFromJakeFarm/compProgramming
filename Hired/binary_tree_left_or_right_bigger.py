from math import ceil, log2

def solution(arr):
    '''
    Array represents binary tree line-by-line; -1 is nonexistant node.
    Is left or right subtree larger?
    '''
    if len(arr) == 0:
        return ''

    left = 0
    right = 0

    start = 1
    for level in range(1, ceil(log2(len(arr)))):
        width = 2 ** level
        for i in range(width):
            if start+i >= len(arr):
                # Reached end of tree
                break

            if arr[start+i] == -1:
                # Nonexistant node
                continue

            if i < width//2:
                left += arr[start+i]
            else:
                right += arr[start+i]

        start += width

    if left == right:
        return ''

    return 'Left' if left > right else 'Right'


arr = [3,6,2,9,-1,10]
print(solution(arr))
