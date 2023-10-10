from collections import deque


class Solution:
    def largestRectangleArea(self, heights: list[int]) -> int:
        max_rect = 0

        # Stack holds (position, height)
        stack = deque([(-1, 0)])
        for i in range(len(heights)):
            cur = heights[i]

            while cur < stack[-1][1]:
                tallest_pos, tallest = stack[-1]
                stack.pop()

                max_rect = max(max_rect, tallest * (i - stack[-1][0] - 1))

            stack.append((i, cur))

        # Clear-out remaining items
        while len(stack) > 1:
            tallest_pos, tallest = stack[-1]
            stack.pop()

            max_rect = max(max_rect, tallest * (i - stack[-1][0]))

        return max_rect

heights = [2,1,5,6,2,3]

S = Solution()
print(S.largestRectangleArea(heights))
