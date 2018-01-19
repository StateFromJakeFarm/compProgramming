birds = int(input())
mymap = {}
for bird in input().strip().split(' '):
    if bird in mymap:
        mymap[bird] += 1
    else:
        mymap[bird] = 1

max_bird = 0
num = 0
for bird in mymap.keys():
    if num < mymap[bird]:
        num = mymap[bird]
        max_bird = bird
print(max_bird)
