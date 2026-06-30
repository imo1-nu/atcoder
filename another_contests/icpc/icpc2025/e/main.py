from sys import setrecursionlimit, stdin

setrecursionlimit(10**6)
# 再帰用
# import pypyjit
# pypyjit.set_param('max_unroll_recursion=-1')


def myin():
    return stdin.readline().rstrip()


def myin_sp():
    return stdin.readline().rstrip().split()


def myin_sp_i():
    return list(map(int, myin_sp()))


def myin_sp_s():
    return list(map(str, myin_sp()))


def main():
    from collections import deque

    while True:
        N = int(myin())
        if N == 0:
            break
        G = [[] for _ in range(N)]
        weight = []
        W = [-1] * N
        for p in range(1, N):
            v, c = myin_sp_i()
            v -= 1
            G[v].append(p)
            G[p].append(v)
            W[p] = c
            weight.append((c, p))
        weight.sort()
        isok = True
        # どうやっても不可能なケース
        for i in range(N - 1):
            if weight[i][0] < i + 1:
                isok = False
                break
        if not isok:
            print("no")
            continue
        # 0からのパスを求める
        que = deque()
        que.append(0)
        seen = [False] * N
        prev = [-1] * N
        while que:
            v = que.popleft()
            if seen[v]:
                continue
            seen[v] = True
            for vv in G[v]:
                if seen[vv]:
                    continue
                prev[vv] = v
                que.append(vv)
        # print(prev)
        t = -1
        ans = []
        # 0からすでにおとずれた
        used = [False] * N
        used[0] = True
        for cost, u in weight:
            if used[u]:
                continue
            now = u
            log = []
            while not used[now]:
                log.append(now)
                now = prev[now]
            log.reverse()
            # print(log)
            for v in log:
                ans.append(v + 1)
                used[v] = True
                t += 1
                # print(f"{t, v, W[v]}")
                if W[v] < t:
                    isok = False
                    break
            if not isok:
                isok = False
                break
            # print(now)
        if isok:
            print("yes")
            print(*ans, sep=" ")
        else:
            print("no")


if __name__ == "__main__":
    main()
