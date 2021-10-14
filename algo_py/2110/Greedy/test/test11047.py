import unittest
import sys, os
sys.path.append(os.path.dirname(os.path.abspath(os.path.dirname(__file__))))
from Coin11047 import *
class test11047(unittest.TestCase):
	def parse(file):
		line = file.readline()
		if not line:
			return False, False, False
		n, k = map(int, line.split())
		coin_value = [0] * n
		for i in range(n):
			coin_value[i] = int(file.readline())
		return n, k, coin_value

	def test_run(self):
		path = 'in11047.txt'
		file = open(path, 'r')
		i = 0
		while True:
			n, k, coin_value = test11047.parse(file)
			if not n:
				print('➰test end')
				break
			answer = int(file.readline())
			self.assertEqual(coin(n, k, coin_value), answer)
			i += 1
		file.close()
if __name__ == '__main__':
	unittest.main()
