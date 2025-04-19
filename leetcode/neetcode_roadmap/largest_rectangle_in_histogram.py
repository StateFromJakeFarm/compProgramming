class Solution:
    def largestRectangleArea(self, heights: list[int]) -> int:
        largest = 0
        stack = []
        for cur_pos, cur_height in enumerate(heights):
            running_height_start = cur_pos
            running_height = cur_height
            while len(stack) and stack[-1][1] >= cur_height:
                # If we found something smaller than the largest thing on the
                # stack, that means those larger things on the stack have no
                # hope of forming a rectangle with a future bar of greater or
                # equal height, so we can just count their max rectangles now
                running_height_start, running_height = stack.pop(-1)
                largest = max(largest, (cur_pos - running_height_start) * running_height)

            if cur_height != 0:
                # Since we've popped everything BIGGER than cur_height, that means
                # the bar of cur_height's rectangle can extend back to the position
                # of the last bar that was greater than or equal to it
                stack.append((running_height_start, cur_height))

        # Empty out the rest of the stack
        for cur_pos, cur_height in stack:
            rect_size = (len(heights) - cur_pos) * cur_height
            largest = max(largest, rect_size)

        return largest

heights = [1,1,1,1,3]

S = Solution()
print(S.largestRectangleArea(heights))
