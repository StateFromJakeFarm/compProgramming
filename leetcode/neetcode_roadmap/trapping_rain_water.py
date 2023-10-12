class Solution:
    def trap(self, heights: list[int]) -> int:
        l = 0
        r = len(heights) - 1

        l_max = heights[l]
        r_max = heights[r]

        total = 0
        while l < r:
            if l_max < r_max:
                # We're about to increment l, so let's see how much water
                # we got at the current position before we move on
                total += max(0, min(l_max, r_max) - heights[l])

                l += 1
                l_max = max(l_max, heights[l])
            else:
                total += max(0, min(l_max, r_max) - heights[r])

                r -= 1
                r_max = max(r_max, heights[r])

        return total


height = [0,1,0,2,1,0,1,3,2,1,2,1]

S = Solution()
print(S.trap(height))
