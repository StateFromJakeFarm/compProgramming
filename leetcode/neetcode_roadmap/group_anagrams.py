class Solution:
    def groupAnagrams(self, words: list[str]) -> list[list[str]]:
        sorted_words = [''.join(sorted(list(w))) for w in words]

        groups = {}
        for i, w in enumerate(sorted_words):
            if w in groups:
                groups[w].append(words[i])
            else:
                groups[w] = [words[i]]

        return list(groups.values())


S = Solution()

strs = ["eat","tea","tan","ate","nat","bat"]
print(S.groupAnagrams(strs))
