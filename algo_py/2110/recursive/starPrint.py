def initStar(n):
	global star
	star = [[0 for i in range(n)] for i in range(n)]
	star[0][:3] = star[2][:3] = [1] * 3
	star[1][:3] = [1, 0, 1]

def printStar(n):
	global star
	size = int(n / 3)
	if size == 1:
		return
	printStar(size)
	for i in range(3):
		for j in range(3):
			if i == 1 and j == 1:
				continue
			for k in range(size):
				star[size * i + k][size * j : size * (j + 1)] = star[k][:size]

size = int(input())
initStar(size)
printStar(size)
for i in star :
	for j in i :
		if j :
			print('*', end = '')
		else :
			print(' ', end = '')
	print()
"""
time over
star = ''
def printStar(n, i, j):
	global star
	scale = int(n / 3)
	if int(i / n) % 3 == 1 and int(j / n) % 3 == 1:
		star += ' '
	else:
		if scale == 0:
			star += '*'
		else:
			printStar(scale, i, j)
scale = int(input())
for i in range(0, scale):
	for j in range(0, scale):
		printStar(scale, i, j)
	if i < scale - 1:
		star += '\n'
print(star)
 """
