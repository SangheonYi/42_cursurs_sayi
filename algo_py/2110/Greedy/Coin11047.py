if __name__ == '__main__':
    n, k = map(int, input().split())
    coin_value = [0] * n
    for i in range(n):
        coin_value[i] = int(input())

def coin(n, k, coin_value):
    m = 0
    for i in range(n - 1, -1, -1):
        m += k // coin_value[i]
        k %= coin_value[i]
    return m
if __name__ == '__main__':
    print(coin(n, k, coin_value), end='')
