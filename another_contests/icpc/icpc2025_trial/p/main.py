while True:
    N = int(input())
    if N == 0:
        break
    A = list(map(int, input().split()))
    print(max(A))
