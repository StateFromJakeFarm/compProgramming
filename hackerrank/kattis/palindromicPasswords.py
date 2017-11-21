PALINDROME_LEN = 6

def main():
    n = input()
    for p in range(n):
        x = list(raw_input())

        for i in reversed(range(PALINDROME_LEN/2, PALINDROME_LEN)):
            a = int(x[PALINDROME_LEN-i-1])
            b = int(x[i])

            x[i] = a

        outStr = ''
        for c in x:
            outStr += str(c)
        print(outStr)

if __name__ == '__main__':
    main()
