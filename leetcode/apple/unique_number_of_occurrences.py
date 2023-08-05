class Solution:
    def uniqueOccurrences(self, arr: list[int]) -> bool:
        counts = {}
        for x in arr:
            counts[x] = counts.get(x, 0) + 1

        return len(set(counts.values())) == len(counts)

S = Solution()

arr = [-3,0,1,-3,1,1,1,-3,10,0]
print(S.uniqueOccurrences(arr))
