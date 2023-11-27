from collections import deque


class Solution:
    def maxSlidingWindow(self, nums: list[int], k: int) -> list[int]:
        Q = deque()
        for i, x in enumerate(nums[:k]):
            # Add element that just came in-range if bigger than
            # any elements already in the queue
            while len(Q) and Q[-1][1] <= x:
                Q.pop()
            if len(Q) < k:
                Q.append((i, x))


        maxes = [Q[0][1]]

        for l in range(1, len(nums) - k + 1):
            # Max for this window is the largest element that is
            # still in-range
            while len(Q) and Q[0][0] < l:
                Q.popleft()

            r = l + k - 1

            # Add element that just came in-range if bigger than
            # any elements already in the queue
            while len(Q) and Q[-1][1] <= nums[r]:
                Q.pop()
            if len(Q) < k:
                Q.append((r, nums[r]))

            maxes.append(Q[0][1])

        return maxes


nums = [1,3,-1,-3,5,3,6,7]
k = 3

S = Solution()
print(S.maxSlidingWindow(nums, k))
