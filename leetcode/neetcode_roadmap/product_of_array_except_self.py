class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        prod = 1
        num_zeros = 0
        for num in nums:
            if num == 0:
                num_zeros += 1

                if num_zeros > 1:
                    return [0 for _ in nums]
            else:
                prod *= num

        if num_zeros == 1:
            return [0 if n != 0 else prod for n in nums]

        return [int(prod/n) if n != 0 else 0 for n in nums]


S = Solution()

nums = [-1,1,0,-3,3]
print(S.productExceptSelf(nums))
