class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        counts = {}
        for n in nums:
            if n in counts:
                counts[n] += 1
            else:
                counts[n] = 1

        counts = [(n, c) for n, c in counts.items()]
        top_k = sorted(counts, key=lambda x: -x[1])[:k]
        return [n for n, c in top_k]


S = Solution()

nums = [1,2,2,3,3,3]
k = 2
print(S.topKFrequent(nums, k))
