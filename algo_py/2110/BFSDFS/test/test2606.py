import unittest
import sys, os
sys.path.append(os.path.dirname(os.path.abspath(os.path.dirname(__file__))))
from Virus2606 import *

class test2606(unittest.TestCase):
	def parse(file):
		n = int(file.readline())
		m = int(file.readline())
		graph = [[] for _ in range(n + 1)]
		check = [False for _ in range(n + 1)]
		for _ in range(m):
			a, b = map(int, file.readline().split())
			graph[a].append(b)
			graph[b].append(a)
		for e in graph:
			e.sort()
		return graph, check

	def test_run(self):
		path = 'in2606.txt'
		file = open(path, 'r')
		i = 0
		graph, check = test2606.parse(file)
		self.assertEqual(bfs(graph, check), int(file.readline()[0]))
		print(f'{i}th test: 💚')
		i += 1
		file.close()
if __name__ == '__main__':
	unittest.main()
