fun main(args: Array<String>) {
	val input = readLine()!!.split(" ")
	val n = input[0].toInt()
	val k = input[1].toInt()
	var i = -1
	var removalI = k - 1
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
		removalI += k - 1
		if(circle.size > 0)
			removalI %= circle.size
	}
	println("circle: $circle")
	println("index: ${removalI} size: ${circle.size}")
	out.delete(out.lastIndex - 1, out.length)
	out.append(">")
	println(out)
}
