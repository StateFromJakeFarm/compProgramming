class Solution:
    def trap(self, a):
        lr = [x for x in a]
        rl = [x for x in a]

        # Get max going l --> r
        for i in range(1, len(a)):
            lr[i] = max(lr[i-1], a[i])

        # Get max going l <-- r
        for i in range(len(a)-2, -1, -1):
            rl[i] = max(rl[i+1], a[i])

        total = 0
        for i in range(len(a)):
            total += (min(lr[i], rl[i]) - a[i])

        return total


s = Solution()

a = [0,1,0,2,1,0,1,3,2,1,2,1]
print(s.trap(a))
