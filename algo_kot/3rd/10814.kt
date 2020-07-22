fun main(args: Array<String>) {
	var pair = arrayOfNulls<Pair<Int, String>>(readLine()!!.toInt())
	for (i in 0 until pair.size)
	{
		var splited = readLine()!!.split(' ')
		pair[i] = Pair<Int, String>(splited[0].toInt(), splited[1])
	}
	pair.sortBy { it!!.first }
	for (i in 0 until pair.size)
		println("${pair[i]!!.first} ${pair[i]!!.second}")
}
