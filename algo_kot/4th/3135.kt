fun main(args: Array<String>) {
	var propa = readLine()!!.split(' ').map { it.toInt() }
	var bookMark = ArrayList<Int>()
	var distance = ArrayList<Int>()
	var n = readLine()!!.toInt()
	var i = -1

	while(++i < n)
	{
		bookMark.add(readLine()!!.toInt())
		distance.add(Math.abs(bookMark[i] - propa[1]) + 1)
	}
	distance.add(Math.abs(propa[0] - propa[1]))
	println(distance.min())
}
