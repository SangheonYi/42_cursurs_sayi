fun main(args: Array<String>) {
	val input = readLine()!!.split(" ")
	val n = input[0].toInt()
	val k = input[1].toInt() - 1
	var i = -1
	var removalI = k
	var circle = MutableList<Int>(n, {a -> a + 1})
	var out = StringBuilder()

	out.append("<")
	while(++i < n)
	{
		out.append(circle[removalI])
		out.append(", ")
		circle.removeAt(removalI)
		removalI += k
		if(circle.size > 0)
			removalI %= circle.size
	}
	out.delete(out.lastIndex - 1, out.length)
	out.append(">")
	println(out)
}
