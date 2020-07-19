fun main(args: Array<String>) {
	var pair = arrayOfNulls<Pair<Int, Int>>(readLine()!!.toInt())
	for (i in 0 until pair.size)
	{
		var splited = readLine()!!.split(' ')
		pair[i] = Pair<Int, Int>(splited[0].toInt(), splited[1].toInt())
	}
	for (i in 0 until pair.size)
	{
		var cnt = 1
		for (j in 0 until pair.size)
		{
			if (pair[i]!!.first < pair[j]!!.first && pair[i]!!.second < pair[j]!!.second)
				cnt++
		}
		print(cnt)
		if (i < pair.size - 1)
			print(" ")
	}
}
