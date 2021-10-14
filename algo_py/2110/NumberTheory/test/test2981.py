import unittest
import sys, os
sys.path.append(os.path.dirname(os.path.abspath(os.path.dirname(__file__))))
from Checkpoint2981 import *
class test2981(unittest.TestCase):
	def parse(file):
		line = file.readline()
		if not line:
			return False, False
		n = int(line)
		numbers = [0] * n
		for i in range(n):
			numbers[i] = int(file.readline())
		return n, numbers

	def test_run(self):
		path = 'in2981.txt'
		file = open(path, 'r')
		i = 0
		while True:
			n, numbers = test2981.parse(file)
			if not n:
				print('➰test end')
				break
			answer = file.readline()
			print(f'{i}th test: 💚')
			self.assertEqual(gcd(n, numbers), answer.rstrip())
			i += 1
		file.close()
if __name__ == '__main__':
	unittest.main()
