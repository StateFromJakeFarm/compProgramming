class Solution:
    def __init__(self):
        self.combos = []


    def recurse(self, nums_idx, stack, stack_sum):
        for i, n in enumerate(self.nums[nums_idx:]):
            if (stack_sum + n) < self.target:
                self.recurse(nums_idx + i, stack + [n], stack_sum + n)
            elif (stack_sum + n) == self.target:
                self.combos.append(stack + [n])


    def combinationSum(self, candidates: list[int], target: int) -> list[list[int]]:
        self.nums = sorted(candidates)
        self.target = target

        self.recurse(0, [], 0)

        return self.combos


S = Solution()

candidates = [2,3,6,7]
target = 7

print(S.combinationSum(candidates, target))
