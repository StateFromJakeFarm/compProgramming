class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        nums = sorted(nums)

        sols = []
        i = 0
        while i < len(nums) - 2:
            j = i + 1
            k = len(nums) - 1
            while j < k:
                summed = nums[i] + nums[j] + nums[k]
                if summed == 0:
                    if len(sols) > 0:
                        last_sol_j = sols[-1][1]
                        last_sol_k = sols[-1][2]

                        if last_sol_j != nums[j] or last_sol_k != nums[k]:
                            sols.append([nums[i], nums[j], nums[k]])
                    else:
                        sols.append([nums[i], nums[j], nums[k]])

                    j += 1
                    k -= 1
                elif summed < 0:
                    j += 1
                else:
                    k -= 1

            i += 1
            while i < len(nums) - 2 and nums[i] == nums[i-1]:
                i += 1

        return sols


nums = [-1,0,1,2,-1,-4]

S = Solution()
print(S.threeSum(nums))
