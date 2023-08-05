class Solution:
    def trap(self, heights: list[int]) -> int:
        if len(heights) <= 2:
            return 0

        l = 0
        r = len(heights) - 1

        l_max = heights[0]
        r_max = heights[-1]

        total = 0

        going_right = True
        while l <= r:
            if going_right:
                l_max = max(l_max, heights[l])
                if l_max > r_max:
                    # Found new highest
                    going_right = False
                else:
                    # Add any water that might be here
                    water = max(0, min(l_max, r_max) - heights[l])
                    total += water

                l += 1
            else:
                r_max = max(r_max, heights[r])
                if r_max > l_max:
                    # Found new highest
                    going_right = True
                else:
                    # Add any water that might be here
                    water = max(0, min(l_max, r_max) - heights[r])
                    total += water

                r -= 1

        return total


heights = [0,1,0,2,1,0,1,3,2,1,2,1]

S = Solution()
print(S.trap(heights))
