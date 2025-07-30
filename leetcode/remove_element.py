class Solution:
    def removeElement(self, nums: list[int], val: int) -> int:
        found = 0
        i = 0
        nums_ = nums
        while i < (len(nums_) - found):
            if nums_[i] == val:
                found += 1
                nums_[i] = nums_[len(nums_) - found]
            else:
                i += 1

        if found > 0:
            nums[:] = nums_[:-found] + [None for _ in range(found)]

        return len(nums_) - found


nums = [3]
val = 2

S = Solution()
print(S.removeElement(nums, val))
print(nums)
