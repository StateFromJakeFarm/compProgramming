class Solution:
    def topKFrequent(self, words: list[str], k: int) -> list[str]:
        counts = {}
        for word in words:
            if word in counts:
                counts[word] += 1
            else:
                counts[word] = 1

        counts = [(k, v) for k, v in counts.items()]

        counts = sorted(counts, key=lambda x: (-x[1], x[0]))[:k]
        return [k for k, v in counts]


words = ["the","day","is","sunny","the","the","the","sunny","is","is"]
k = 4

S = Solution()
print(S.topKFrequent(words, k))
