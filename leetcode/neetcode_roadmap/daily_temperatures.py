class Solution:
    def dailyTemperatures(self, temperatures: list[int]) -> list[int]:
        answer = [0 for t in temperatures]

        stack = []
        for i, t in enumerate(temperatures):
            while len(stack) and stack[-1][0] < t:
                _, past_i = stack.pop(-1)
                answer[past_i] = i - past_i

            stack.append((t, i))

        return answer


temperatures = [73,74,75,71,69,72,76,73]
#temperatures = [30,40,50,60]
#temperatures = [30,60,90]

S = Solution()
print(S.dailyTemperatures(temperatures))
