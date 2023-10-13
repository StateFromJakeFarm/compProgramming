class TimeMap:
    def __init__(self):
        self.D = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.D:
            self.D[key] = [(value, timestamp)]
        else:
            self.D[key].append((value, timestamp))

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.D or self.D[key][0][1] > timestamp:
            return ''

        if timestamp > self.D[key][-1][1]:
            return self.D[key][-1][0]

        lo = 0
        hi = len(self.D[key]) - 1
        while lo < hi:
            mid = (lo + hi) // 2
            if self.D[key][mid][1] == timestamp:
                return self.D[key][mid][0]
            if mid == hi - 1 and self.D[key][mid][1] < timestamp and timestamp < self.D[key][hi][1]:
                return self.D[key][mid][0]

            if timestamp < self.D[key][mid][1]:
                hi = mid - 1
            else:
                lo = mid + 1

        return self.D[key][lo][0]


# Your TimeMap object will be instantiated and called as such:
obj = TimeMap()
obj.set('foo', 'bar', 1)
obj.get('foo', 1)
obj.get('foo', 3)
obj.set('foo', 'bar2', 4)
obj.get('foo', 4)
obj.get('foo', 5)
