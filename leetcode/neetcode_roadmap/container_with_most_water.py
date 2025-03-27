class Solution:
    def maxArea(self, heights: list[int]) -> int:
        i = 0
        j = len(heights) - 1
        best = 0
        while i < j:
            area = (j-i) * min(heights[i], heights[j])
            best = max(best, area)

            if heights[i] < heights[j]:
                i += 1
            elif heights[i] > heights[j]:
                j -= 1
            else:
                i += 1
                j -= 1

        return best


S = Solution()
height = [1,7,2,5,4,7,3,6]
print(S.maxArea(height))
