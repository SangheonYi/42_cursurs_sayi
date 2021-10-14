from math import sqrt
if __name__ == '__main__':
    n = int(input())
    numbers = [0] * n
    for i in range(n):
        numbers[i] = int(input())

def checkCommon(difference, target):
    for e in difference:
        if e % target != 0:
            return False
    return True
def gcd(n, numbers):
    out = ''
    numbers.sort()
    difference = [0] * (n - 1)
    for i in range(n - 1):
        difference[i] = numbers[i + 1] - numbers[i]
    candidate = [difference[0]]
    i = 2
    limit = sqrt(difference[0] + 1)
    while i <= limit:
        if difference[0] % i == 0:
            if checkCommon(difference, i):
                out += f'{i} '
            share = difference[0] // i
            if i != share:
                candidate.append(share)
        i += 1
    out_tail = ''
    for e in candidate:
        if checkCommon(difference, e):
            out_tail = f'{e} {out_tail}'
    return f'{out}{out_tail}'.rstrip()

if __name__ == '__main__':
    print(gcd(n, numbers), end='\n')
