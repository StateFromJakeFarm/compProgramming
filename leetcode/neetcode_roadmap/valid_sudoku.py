class Solution:
    def checkRow(self, board, r):
        seen = [False for _ in range(9)]
        for i in range(9):
            num = board[r][i]
            if num == '.':
                continue

            num = int(num)
            num -= 1
            if seen[num]:
                return False
            seen[num] = True

        return True


    def checkCol(self, board, c):
        seen = [False for _ in range(9)]
        for i in range(9):
            num = board[i][c]
            if num == '.':
                continue

            num = int(num)
            num -= 1
            if seen[num]:
                return False
            seen[num] = True

        return True


    def checkSquare(self, board, s):
        r = int(s / 3) * 3
        c = (s % 3) * 3

        seen = [False for _ in range(9)]
        for i in range(3):
            for j in range(3):
                num = board[r + i][c + j]
                if num == '.':
                    continue

                num = int(num)
                num -= 1
                if seen[num]:
                    return False
                seen[num] = True

        return True


    def isValidSudoku(self, board: list[list[str]]) -> bool:
        for i in range(9):
            if not self.checkRow(board, i):
                return False
            if not self.checkCol(board, i):
                return False
            if not self.checkSquare(board, i):
                return False

        return True


S = Solution()

board = [
    ["5","3",".",".","7",".",".",".","."],
    ["6",".",".","1","9","5",".",".","."],
    [".","9","8",".",".",".",".","6","."],
    ["8",".",".",".","6",".",".",".","3"],
    ["4",".",".","8",".","3",".",".","1"],
    ["7",".",".",".","2",".",".",".","6"],
    [".","6",".",".",".",".","2","8","."],
    [".",".",".","4","1","9",".",".","5"],
    [".",".",".",".","8",".",".","7","9"]
]
print(S.isValidSudoku(board))
