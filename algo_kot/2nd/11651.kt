fun main(args: Array<String>) {
	var pair = arrayOfNulls<Pair<Int, Int>>(readLine()!!.toInt())
	for (i in 0 until pair.size)
	{
		var splited = readLine()!!.split(' ')
		pair[i] = Pair<Int, Int>(splited[0].toInt(), splited[1].toInt())
	}
	pair.sortWith(compareBy({it!!.second}, {it!!.first}))
	for (i in 0 until pair.size)
		println("${pair[i]!!.first} ${pair[i]!!.second}")
}
