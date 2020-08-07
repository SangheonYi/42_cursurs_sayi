fun main() {
	var input = arrayListOf<Int>()
	var i = -1
	val j = readLine()!!.toInt()
	val output = StringBuilder()
	while (++i < j)
		input.add(readLine()!!.toInt())
	input.sort()
	i = -1
	while (++i < j)
	{
		output.append(input[i])
		output.append("\n")
	}
	output.deleteCharAt(output.length - 1)
	println(output)
}
