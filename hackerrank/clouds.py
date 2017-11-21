num_clouds = input()
clouds = [int(x) for x in input().split()]

jumps = 0
cur = 0
dest = len(clouds) - 1
while(cur != dest):
    if cur+2 <= dest and clouds[cur+2] != 1:
        cur += 2
    else:
        cur += 1

    jumps += 1

print(jumps)
