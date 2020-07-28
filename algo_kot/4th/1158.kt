fun main(args: Array<String>) {
	val input = readLine()!!.split(" ")
	val n = input[0].toInt()
	val k = input[1].toInt() - 1
	var i = -1
	var removalI = k
	var circle = MutableList<Int>(n, {a -> a + 1})
	var out = StringBuilder()

	out.append("<")
	println(circle.size)
	while(++i < n)
	{
		println("circle: $circle")
		println("index: ${removalI} size: ${circle.size}")
		out.append(circle[removalI])
		out.append(", ")
		println("removing: ${circle.removeAt(removalI)}")
		removalI += k
		if(circle.size > 0)
			removalI %= circle.size
	}
	println("circle: $circle")
	println("index: ${removalI} size: ${circle.size}")
	out.delete(out.lastIndex - 1, out.length)
	out.append(">")
	println(out)
}
