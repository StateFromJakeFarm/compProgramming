class TimeMap:

    def __init__(self):
        self.vals = {}


    def set(self, key: str, value: str, timestamp: int) -> None:
        if key in self.vals:
            self.vals[key].append((timestamp, value))
        else:
            self.vals[key] = [(timestamp, value)]


    def get(self, key: str, timestamp: int) -> str:
        if key not in self.vals:
            return ''

        L = self.vals[key]

        if L[-1][0] <= timestamp:
            return L[-1][1]

        if L[0][0] > timestamp:
            return ''

        lo, hi = 0, len(L) - 1
        while lo < hi:
            mid = (lo + hi) // 2
            mid_timestamp = L[mid][0]

            if mid_timestamp == timestamp:
                return L[mid][1]

            if mid_timestamp < timestamp:
                lo = mid + 1
            else:
                hi = mid - 1

        if L[lo][0] <= timestamp:
            return L[lo][1]

        if (lo > 0):
            return L[lo-1][1]

        return L[0][1]


obj = TimeMap()

actions = ["set","set","set","set","get"]
params = [["foo","bar",1],["foo", "toilet", 5],["foo", "bucket", 10],["foo","bar2",20],["foo",15]]
for a, p in zip(actions, params):
    if a == 'set':
        obj.set(*p)
        print(None)
    else:
        print(obj.get(*p))
