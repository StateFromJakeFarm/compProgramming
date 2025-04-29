class Solution:
    def twoSum(self, numbers: list[int], target: int) -> list[int]:
        i = 0
        j = len(numbers) - 1

        while i < j:
            summed = numbers[i] + numbers[j]
            if summed == target:
                return [i+1, j+1]
            if summed < target:
                i += 1
            else:
                j -= 1
