fun main(args: Array<String>) {
	var propa = readLine()!!.split(' ')
	var bookMark = arrayListOf<Int>(readLine()!!.toInt())
	var distance = arrayListOf<Int>(bookMark.size + 1)
	var i = -1

	while(++i < bookMark.size)
	{
		bookMark[i] = readLine()!!.toInt()
		distance[i] = Math.abs(bookMark[i] - propa[1]) + 1
	}
	distance[distance.lastindex] = Math.abs(propa[0] - propa[1])
	println(distance.min())
}
