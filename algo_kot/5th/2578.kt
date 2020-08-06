fun main(args: Array<String>) {
	var i = -1
	var input = List<List<Int>>(5, {readLine()!!.split(' ').map { it.toInt() }})
	while (++i < 5)
	{
		println(input[i])
	}
}
