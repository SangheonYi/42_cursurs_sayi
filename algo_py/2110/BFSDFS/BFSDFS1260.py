#sangheon
def readInt(read):
    return [int(e) for e in read.split() if e != ' ']

def initList(size):
    return [[] for i in range(size)]

def dfs(graph, n, v):
    stack = [v]
    check = [False for _ in range(n + 1)]
    out = ''
    while stack:
        visiting = stack.pop()
        if not check[visiting]:
            out += f'{visiting} '
            check[visiting] = True
        reversedIterator = reversed(graph[visiting])
        for _ in graph[visiting]:
            e = next(reversedIterator)
            if not check[e]:
                stack.append(e)
    return out.rstrip() + '\n'

def bfs(graph, n, v):
    que = [v]
    check = [False for _ in range(n + 1)]
    out = ''
    while que:
        visiting = que.pop(0)
        if not check[visiting]:
            out += f'{visiting} '
            check[visiting] = True
        for e in graph[visiting]:
            if not check[e]:
                que.append(e)
    return out.rstrip()
if __name__ == '__main__':
    n, m, v = map(int, input().split())
    graph = initList(n + 1)
    for _ in range(m):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)
    for e in graph:
        e.sort()
    print(dfs(graph, n, v), end='')
    print(bfs(graph, n, v), end='')
