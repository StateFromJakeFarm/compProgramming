class Solution:
    def trap(self, heights: list[int]) -> int:
        total = 0

        l = 0
        r = len(heights) - 1
        l_max = heights[l]
        r_max = heights[r]
        while l < r:
            if heights[l] < heights[r]:
                l_max = max(l_max, heights[l])
                total += l_max - heights[l]
                l += 1
            else:
                r_max = max(r_max, heights[r])
                total += r_max - heights[r]
                r -= 1

        return total


heights = [0,2,0,3,1,0,1,3,2,1]

S = Solution()
print(S.trap(heights))
