
def main():
    n = int(input())
    res = []
    while True:
        res.append(n)
        if n == 1:
            break 
        elif n%2 == 0:
            n //= 2 
        else:
            n = n*3 + 1
    print(' '.join(map(str,res)))

if __name__ == "__main__":
    main()
