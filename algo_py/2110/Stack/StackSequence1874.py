# https://st-lab.tistory.com/182
from collections import deque
if __name__ == '__main__':
    n = int(input())
    sequence = [0] * n
    for i in range(n):
        sequence[i] = int(input())
def trySequece(n, sequence):
    out = ''
    stack = []
    deq = deque()
    for i in range(1, n + 1):
        deq.append(i)
    for e in sequence:
        while (len(stack) > 0 and e > stack[len(stack) - 1]) or len(stack) == 0:
            stack.append(deq.popleft())
            out += '+\n'
        if (e < stack[len(stack) - 1]):
            return 'NO'
        else:
            stack.pop()
            out += '-\n'
    return out.rstrip('\n')
if __name__ == '__main__':
    print(trySequece(n, sequence), end='')

