from collections import deque

class Solution:
    def dailyTemperatures(self, temperatures: list[int]) -> list[int]:
        big_to_small = deque()
        answers = [0 for _ in temperatures]

        for i in range(len(temperatures)):
            while len(big_to_small) > 0:
                top = big_to_small[-1]
                if temperatures[i] > temperatures[top]:
                    answers[top] = i - top
                    big_to_small.pop()
                else:
                    break

            big_to_small.append(i)

        return answers


temperatures = [73,74,75,71,69,72,76,73]

S = Solution()
print(S.dailyTemperatures(temperatures))
