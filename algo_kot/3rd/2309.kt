fun main(args: Array<String>) {
	var input = IntArray(9)
	var sum:Int

	for (i in 0 until input.size)
		input[i] = readLine()!!.toInt()
	sum = input.sum()
	for (i in 0 until input.size - 1)
	{
		for (j in (i + 1) until input.size)
		{
			if (sum - input[i] - input[j] == 100)
			{
				input[i] = 0
				input[j] = 0
				sum = 100
				break
			}
		}
		if (sum == 100) break
	}
	input.sort()
	for (i in 2 until input.size)
		println(input[i])
}
