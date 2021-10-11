import unittest
import sys, os
sys.path.append(os.path.dirname(os.path.abspath(os.path.dirname(__file__))))
from NQueen9663 import *

class test9663(unittest.TestCase):
	def parse(file):
		n = int(file.readline())
		return n

	def test_run(self):
		path = 'in9663.txt'
		file = open(path, 'r')
		i = 0
		n = test9663.parse(file)
		self.assertEqual(NQueen(n), int(file.readline()))
		print(f'{i}th test: 💚')
		i += 1
		file.close()
if __name__ == '__main__':
	unittest.main()
