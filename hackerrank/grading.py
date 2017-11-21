import math

n = int(input())
for i in range(n):
    grade = int(input())
    if grade >= 38:
        mult_five = int((math.floor((grade / 5)+1))*5)
        if mult_five - grade < 3:
            grade = mult_five
    print(grade)
