
def main():
    n = int(input())
    arr = list(map(int, input().split()))
    res =  0 
    for i in range(1, n):
        if arr[i-1] >= arr[i]:
            res += (arr[i-1]-arr[i])
            arr[i] = arr[i-1] 
    print(res) 
    

if __name__ == "__main__":
    main()
