import math
import sys

def decomposeMe(n, sumNum):
    myList = []

    if n == 0:
        return myList

    curNum = math.floor(math.sqrt(n))
    if n == sumNum:
        curNum -= 1

    while(curNum > 0):
        whatsLeft = n - curNum**2
        myList = decomposeMe(whatsLeft, sumNum)

        if myList == None or curNum in myList:
            curNum -= 1
        else:
            myList.append(int(curNum))
            return myList

    return None

def decompose(n):
    n *= n
    return decomposeMe(n, n)


print(decompose(int(sys.argv[1])))
