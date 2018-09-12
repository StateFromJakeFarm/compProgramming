# Square dim
n = 3

def rotate_square(s):
    '''Rotate a square 90 degrees'''
    temp = [r[:] for r in s]
    for r in range(n):
        for c in range(n):
            temp[c][n-1-r] = s[r][c]

    return temp

def square_diff(s1, s2):
    '''Get arithmetic difference between two squares'''
    diff = 0
    for r in range(n):
        for c in range(n):
            diff += abs(s1[r][c] - s2[r][c])

    return diff

# The only 3x3 magic square
magic_square = [[8, 3, 4],
                [1, 5, 9],
                [6, 7, 2]]

# Get input square
input_square = []
for i in range(n):
    input_square.append([int(x) for x in raw_input().split()])

# Get min diff between input square and every rotation of the magic square and its transpose
min_diff = 99999
for t in range(2):
    for r in range(4):
        min_diff = min(min_diff, square_diff(magic_square, input_square))

        magic_square = rotate_square(magic_square)

    magic_square = [list(x) for x in zip(*magic_square)]

print(min_diff)
