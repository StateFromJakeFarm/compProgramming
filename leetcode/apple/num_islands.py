class Solution:
    def numIslands(self, grid: list[list[str]]) -> int:
        counter = 0
        for r in range(len(grid)):
            for c in range(len(grid[0])):
                if grid[r][c] == '1':
                    counter += 1

                    # This is stupid, but I'm just pasting the flood fill code here instead of putting into a function
                    # because doing so would mean I have to copy the entire grid either as a class attribute or an
                    # argument and this blows the memory on LeetCode
                    Q = [(r, c)]
                    while len(Q) > 0:
                        # Algorithmically, it doesn't matter if we pop from the back or front because the same number of elements and
                        # checks happen regardless.  Popping from the back of the list is O(1) whereas from the front is O(n), so
                        # we get a speed boost.
                        i, j = Q[-1]
                        Q.pop()

                        grid[i][j] = '^'

                        if i > 0 and grid[i-1][j] == '1':
                            Q.append((i-1, j))
                        if j > 0 and grid[i][j-1] == '1':
                            Q.append((i, j-1))
                        if i < len(grid) - 1 and grid[i+1][j] == '1':
                            Q.append((i+1, j))
                        if j < len(grid[0]) - 1 and grid[i][j+1] == '1':
                            Q.append((i, j+1))


        return counter


grid = [
  ["1","1","1","1","0"],
  ["0","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]

S = Solution()
print(S.numIslands(grid))
