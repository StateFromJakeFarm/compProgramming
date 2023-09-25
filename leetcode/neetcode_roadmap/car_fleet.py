class Solution:
    def carFleet(self, target: int, position: list[int], speed: list[int]) -> int:
        cars = [[p, s] for p, s in zip(position, speed)]
        cars = sorted(cars, key=lambda x: -x[0])

        n = len(cars)
        t_front = 0
        for position, speed in cars:
            t = (target - position) / speed
            if t <= t_front:
                n -= 1
            else:
                t_front = t

        return n


target = 12
position = [10,8,0,5,3]
speed = [2,4,1,1,3]

target = 10
position = [0,4,2]
speed = [2,1,3]

S = Solution()
print(S.carFleet(target, position, speed))
