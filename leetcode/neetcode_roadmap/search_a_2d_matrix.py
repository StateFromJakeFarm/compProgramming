class Solution:
    def searchRow(self, row_idx):
        lo = 0
        hi = len(self.matrix[row_idx]) - 1

        while lo <= hi:
            idx = (lo + hi) // 2
            if self.matrix[row_idx][idx] == self.target:
                return True

            if self.matrix[row_idx][idx] < self.target:
                lo = idx + 1
            else:
                hi = idx - 1

        return False


    def searchForRow(self):
        lo = 0
        hi = len(self.matrix) - 1

        while lo < hi:
            idx = (lo + hi) // 2
            if idx == len(self.matrix) - 1:
                # Reached last row; it's here or not present at all
                return self.searchRow(idx)
            if self.matrix[idx][0] <= self.target and self.target < self.matrix[idx+1][0]:
                # It's either in this row or not present
                return self.searchRow(idx)
            elif self.target < self.matrix[idx][0]:
                # Target is less than smallest element in row, so go backwards
                hi = idx - 1
            else:
                # Target is bigger than smallest element in row BUT also bigger than smallest
                # element in next row, so we know it's ahead of the current row
                lo = idx + 1

        return self.searchRow(lo)


    def searchMatrix(self, matrix: list[list[int]], target: int) -> bool:
        self.matrix = matrix
        self.target = target

        return self.searchForRow()


matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]]
target = 3

S = Solution()

print(S.searchMatrix(matrix, target))
