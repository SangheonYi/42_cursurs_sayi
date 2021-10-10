cnt = 0
moveLog = []
def move(origin, to):
	global cnt
	cnt += 1
	moveLog.append(str(origin) + ' ' + str(to))
def hanoi(n, origin, to, via):
	if n == 1:
		move(origin, to)
	else:
		hanoi(n - 1, origin, via, to)
		move(origin, to)
		hanoi(n - 1, via, to, origin)
n = int(input())
hanoi(n, 1, 3, 2)
print(cnt)
for e in moveLog:
	print(e)
