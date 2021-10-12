import unittest
import sys, os
sys.path.append(os.path.dirname(os.path.abspath(os.path.dirname(__file__))))
from Fibo1003 import *
class test1003(unittest.TestCase):
	def parse(file):
		n = int(file.readline())
		line = []
		if not n:
			return False, False, False
		for _ in range(n):
			line.append(int(input()))
		return n, line

	def test_run(self):
		path = 'in1003.txt'
		file = open(path, 'r')
		i = 0
		while True:
			n, v, graph = test1003.parse(file)
			if not n:
				print('➰test end')
				break
			self.assertEqual(dfs(graph, n, v), file.readline())
			self.assertEqual(bfs(graph, n, v), file.readline().rstrip('\n'))
			print(f'{i}th test: 💚')
			i += 1
		file.close()
if __name__ == '__main__':
	unittest.main()
