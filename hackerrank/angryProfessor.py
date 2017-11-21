T = input()

for i in range(T):
    threshold = int(raw_input().split(' ')[1])

    num_on_time = 0
    for t in [int(x) for x in raw_input().split(' ')]:
        if t <= 0:
            num_on_time += 1

    if num_on_time < threshold:
        print 'YES'
    else:
        print 'NO'
