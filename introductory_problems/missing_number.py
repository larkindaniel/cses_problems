def main():
    n = int(input())
    st = set(map(int, input().split()))

    for i in range(1,n+1):
        if i not in st:
            print(i)
            return 
    

if __name__ == "__main__":
    main()
