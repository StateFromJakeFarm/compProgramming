import sys

T = int(input())
blank = input()

n = m = 0
grid = []
visited = []
water_points = []
ans = 0

dr = [1,1,0,-1,-1,-1,0,1]
dc = [0,1,1,1,0,-1,-1,-1]

def flood(r, c):
    if r < 0 or r >= len(grid) or c < 0 or c >= len(grid[0]):
        return 0

    if visited[r][c] == ' ' or grid[r][c] == 'L':
        return 0
    visited[r][c] = ' '

    ans = 1

    for d in range(8):
        ans += flood(r + dr[d], c + dc[d])
    return ans

def solve(water_points):
    for point in water_points:
        ans = flood(point[0]-1, point[1]-1)
        print(ans)

# MAIN
for line in sys.stdin:
    line = line.strip()

    m = len(line)
    if line != '' and len(line) == len(line.split(' ')[0]):
        line_list = [x for x in line]
        grid.append(line_list)
        visited.append(line_list)
        n += 1
    elif line == '':
        solve(water_points)
        grid = []
        visited = []
        water_points = []
        n = m = 0
        ans = 0
    else:
        water_points.append( [int(x) for x in line.split(' ')] )

solve(water_points)
