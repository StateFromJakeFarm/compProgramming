class Solution:
    class MaxHeapObj(object):
        def __init__(self, val): self.val = val
        def __lt__(self, other): return self.val > other.val
        def __eq__(self, other): return self.val == other.val
        def __str__(self): return str(self.val)

    def furthestBuilding(self, heights: list[int], bricks: int, ladders: int) -> int:
        import heapq

        gaps = []
        for i in range(len(heights)):
            if i == len(heights) - 1:
                # Reached the end!
                return i

            if heights[i] >= heights[i+1]:
                # Advance at no cost
                continue

            # Keep track of this gap we're having to cross
            heapq.heappush(gaps, Solution.MaxHeapObj(heights[i+1] - heights[i]))

            bricks -= heights[i+1] - heights[i]

            if bricks < 0:
                if ladders > 0:
                    # Have to use a ladder; put it on biggest gap to be most efficient with use of bricks
                    biggest_gap = heapq.heappop(gaps).val
                    bricks += biggest_gap

                    ladders -= 1
                else:
                    return i


heights = [4,12,2,7,3,18,20,3,19]
bricks = 10
ladders = 2

heights = [4,2,7,6,9,14,12]
bricks = 5
ladders = 1

heights = [14,3,19,3]
bricks = 17
ladders = 0

S = Solution()

print(S.furthestBuilding(heights, bricks, ladders))
