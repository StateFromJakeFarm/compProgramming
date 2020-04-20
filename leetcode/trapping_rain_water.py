class Solution:
    def trap(self, a):
        if len(a) < 2:
            return 0

        i, j = 0, len(a) - 1
        l_max, r_max = a[i], a[j]

        total = 0
        while i < j:
            if a[i] < a[j] or a[i] == a[j]:
                total += l_max - a[i]

                i += 1
                l_max = max(l_max, a[i])
            else:
                total += r_max - a[j]

                j -= 1
                r_max = max(r_max, a[j])

        return total


s = Solution()

a = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
print(s.trap(a))
