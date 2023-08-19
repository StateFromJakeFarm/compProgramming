class Solution:
    def is_wall(self, r, c):
        return (
            r < 0
            or r >= len(self.maze)
            or c < 0
            or c >= len(self.maze[0])
            or self.maze[r][c] == 1
        )


    def kick(self, loc, d):
        r, c = loc

        while True:
            if d == 'u':
                if self.is_wall(r-1, c):
                    break
                r -= 1
            elif d == 'd':
                if self.is_wall(r+1, c):
                    break
                r += 1
            elif d == 'l':
                if self.is_wall(r, c-1):
                    break
                c -= 1
            else:
                if self.is_wall(r, c+1):
                    break
                c += 1

        return r, c


    def hasPath(self, maze: list[list[int]], start: list[int], destination: list[int]) -> bool:
        self.maze = maze

        Q = [start]
        while len(Q) > 0:

            loc = Q[0]
            Q.pop(0)

            r, c = loc
            self.maze[r][c] = -1

            for d in ['u', 'd', 'l', 'r']:
                new_r, new_c = self.kick(loc, d)

                if [new_r, new_c] == destination:
                    # Success
                    return True

                if self.maze[new_r][new_c] != -1:
                    # New location, add it to the queue
                    Q.append([new_r, new_c])

        return False


maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]]
start = [0,4]
destination = [4,4]

S = Solution()
print(S.hasPath(maze, start, destination))
