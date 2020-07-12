fun main() {
	val lineNum = readLine()!!.toInt()
	for (line in 1 .. lineNum) {
		var args: List<String> =  readLine()!!.split(' ')
		var result:StringBuilder = StringBuilder()
		for (i in 0 until args[1].length) {
			for (i2 in 1 .. args[0].toInt())
				result.append(args[1][i])
		}
		println(result)
	}
}
