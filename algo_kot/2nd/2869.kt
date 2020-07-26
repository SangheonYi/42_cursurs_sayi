fun main(args: Array<String>) {
	val input = readLine()!!.split(' ')
	val A:Int = input[0].toInt()
	val B:Int = input[1].toInt()
	var V:Int = input[2].toInt()
	V -= A
	if (V <= 0)
		println(1)
	else if (V % (A - B) == 0)
		println(1 + V / (A - B))
	else
		println(2 + V / (A - B))
}
