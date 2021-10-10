from posixpath import join


if __name__ == '__main__':
    n, m = map(int, input().split())
out = ''
pick = []

def dfs(n, m, depth, out):
        if len(pick) == m:
            out += ' '.join(map(str, pick)) + '\n'
            return out
        for i in range(1, n + 1):
            if i not in pick:
                pick.append(i)
                out = dfs(n, m, depth + 1, out)
                pick.pop()
        return out

if __name__ == '__main__':
    print(dfs(n, m, 0, out).rstrip('\n'))
