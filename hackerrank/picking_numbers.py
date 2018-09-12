counts = [0 for i in range(100)]

l = raw_input()
for a in raw_input().split():
    counts[int(a)] += 1

biggest_list = -1
for i in range(len(counts[:-1])):
    biggest_list = max(biggest_list, counts[i] + counts[i+1])

print(biggest_list)
