class Solution:
    def isValidSudoku(self, board: list[list[str]]) -> bool:
        square_sets = [[set() for j in range(3)] for i in range(3)]

        # Check rows
        for i in range(9):
            cur_set = set()
            for j in range(9):
                if board[i][j] == '.':
                    continue

                if board[i][j] in cur_set:
                    return False
                cur_set.update(board[i][j])

                # Check squares while we check rows
                s_i = i // 3
                s_j = j // 3
                if board[i][j] in square_sets[s_i][s_j]:
                    return False
                square_sets[s_i][s_j].update(board[i][j])

        # Check cols
        for j in range(9):
            cur_set = set()
            for i in range(9):
                if board[i][j] == '.':
                    continue

                if board[i][j] in cur_set:
                    return False
                cur_set.update(board[i][j])

        return True

board = \
[[".",".","4",".",".",".","6","3","."]
,[".",".",".",".",".",".",".",".","."]
,["5",".",".",".",".",".",".","9","."]
,[".",".",".","5","6",".",".",".","."]
,["4",".","3",".",".",".",".",".","1"]
,[".",".",".","7",".",".",".",".","."]
,[".",".",".","5",".",".",".",".","."]
,[".",".",".",".",".",".",".",".","."]
,[".",".",".",".",".",".",".",".","."]]

S = Solution()

print(S.isValidSudoku(board))
