import unittest
import sys, os
sys.path.append(os.path.dirname(os.path.abspath(os.path.dirname(__file__))))
from BFSDFS1260 import *
class test1260(unittest.TestCase):
	def parse(file):
		line = file.readline()
		if not line:
			return False, False, False
		n, m, v = map(int, line.split())
		graph = initList(n + 1)
		for _ in range(m):
			a, b = map(int, file.readline().split())
			graph[a].append(b)
			graph[b].append(a)
		for e in graph:
			e.sort()
		return n, v, graph

	def test_run(self):
		path = 'in1260.txt'
		file = open(path, 'r')
		i = 0
		while True:
			n, v, graph = test1260.parse(file)
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
