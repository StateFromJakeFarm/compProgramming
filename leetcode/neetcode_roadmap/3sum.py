class Solution:
    def twoSum(self, nums, cutoff, target):
        i_prev = 100001

        i = cutoff + 1
        j = len(nums) - 1

        sols = []
        while i < j:
            summed = nums[i] + nums[j]
            # Only add the solution if we didn't already use these two values previously (check with i_prev)
            if summed == target and nums[i] != i_prev:
                i_prev = nums[i]
                sols.append([nums[i], nums[j]])
                i += 1
                j -= 1
            elif summed < target:
                i += 1
            else:
                j -= 1

        return sols


    def threeSum(self, nums: list[int]) -> list[list[int]]:
        nums = sorted(nums)
        if (nums[0] < 0 and nums[-1] < 0) or (nums[0] > 0 and nums[-1] > 0):
            return []

        triplets = []
        prev_cutoff = 100001
        for cutoff in range(len(nums) - 2):
            if nums[cutoff] == prev_cutoff:
                # If we walk over the same number twice, we know we've already
                # gotten all unique combos for it from twoSum(), so skip it
                continue

            target = -nums[cutoff]

            for sol in self.twoSum(nums, cutoff, target):
                triplets.append([nums[cutoff]] + sol)

            prev_cutoff = nums[cutoff]

        return triplets

nums = [-1,0,1,2,-1,-4]

S = Solution()
print(S.threeSum(nums))
