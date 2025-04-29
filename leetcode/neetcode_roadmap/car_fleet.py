class Solution:
    def carFleet(self, target: int, position: list[int], speed: list[int]) -> int:
        cars = sorted(list(zip(position, speed)), key=lambda x: x[0])
        fleet_times = []
        for p, s in cars:
            car_time = (target - p) / s
            while len(fleet_times) and car_time >= fleet_times[-1]:
                fleet_times.pop(-1)

            fleet_times.append(car_time)

        return len(fleet_times)


target = 12
position = [10,8,0,5,3]
speed = [2,4,1,1,3]


S = Solution()
print(S.carFleet(target, position, speed))
