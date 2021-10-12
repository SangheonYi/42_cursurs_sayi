n = int(input())
case = []
zero = [1, 0, 1, 1]
one = [0, 1, 1, 2]
answer = ''
for _ in range(n):
    case.append(int(input()))

def getFiboElement(n, zero, one):
    computedN = len(zero)
    if n >= computedN:
        n_2 = computedN - 2
        n_1 = computedN - 1
        for i in range(n - computedN + 1):
            zero.append(zero[n_2 + i] + zero[n_1 + i])
            one.append(one[n_2 + i] + one[n_1 + i])
    return f'{zero[n]} {one[n]}\n'

for e in case:
    answer += getFiboElement(e, zero, one)
print(answer.rstrip('\n'), end='')
