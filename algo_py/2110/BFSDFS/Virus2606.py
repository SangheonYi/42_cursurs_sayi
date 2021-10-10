#sangheon
if __name__ == '__main__':
    n = int(input())
    m = int(input())
    graph = [[] for _ in range(n + 1)]
    check = [False for _ in range(n + 1)]
    for _ in range(m):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)

def bfs(graph, check):
    que = [1]
    while que:
        visiting = que.pop(0)
        if not check[visiting]:
            check[visiting] = True
        for e in graph[visiting]:
            if not check[e]:
                que.append(e)
    if __name__ == '__main__':
        print(sum(check) - 1, end = '')
    else:
        return sum(check) - 1
if __name__ == '__main__':
    bfs(graph, check)
