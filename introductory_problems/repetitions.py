
def main():
    sequence = str(input())
    N = len(sequence)
    res = 1 
    cur = 1 
    for i in range(1, N):
        if sequence[i-1] == sequence[i]:
            cur += 1
        else:
            cur = 1
        res = max(res, cur)
    print(res)

if __name__ == "__main__":
    main()
