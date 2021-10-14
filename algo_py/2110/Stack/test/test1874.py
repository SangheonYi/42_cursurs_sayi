import unittest
import sys, os
sys.path.append(os.path.dirname(os.path.abspath(os.path.dirname(__file__))))
from StackSequence1874 import *
class test1874(unittest.TestCase):
	def parse(file):
		line = file.readline()
		if not line:
			return False, False
		n = int(line)
		sequence = [0] * n
		for i in range(n):
			sequence[i] = int(file.readline())
		return n, sequence

	def test_run(self):
		path = 'in1874.txt'
		file = open(path, 'r')
		i = 0
		while True:
			answer = ''
			n, sequence = test1874.parse(file)
			if not n:
				print('➰test end')
				break
			line = file.readline()
			while line != 'below next input\n':
				answer += line
				line = file.readline()
			print(f'{i}th test: 💚')
			self.assertEqual(trySequece(n, sequence), answer.rstrip())
			i += 1
		file.close()
if __name__ == '__main__':
	unittest.main()
