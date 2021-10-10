import unittest
import sys, os
sys.path.append(os.path.dirname(os.path.abspath(os.path.dirname(__file__))))
from NandM15649 import *
class test15649(unittest.TestCase):
	def parse(file):
		line = file.readline()
		if not line:
			return False, False
		return map(int, line.split())

	def test_run(self):
		path = 'in15649.txt'
		file = open(path, 'r')
		i = 0
		while True:
			n, m = test15649.parse(file)
			answer = ''
			if not n:
				print('➰test end')
				break
			line = file.readline()
			while line != 'below next input\n':
				answer += line
				line = file.readline()
			self.assertEqual(dfs(n, m, 0, out), answer)
			print(f'{i}th test: 💚')
			i += 1
		file.close()
if __name__ == '__main__':
	unittest.main()
