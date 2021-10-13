def getFiboElement(n):
    tile = [1, 2]
    if n >= 2:
        for i in range(2, n):
            tile.append((tile[i - 2] + tile[i - 1])%15746)
    return tile[n - 1]
print(getFiboElement(int(input())), end='')
