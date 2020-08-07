fun main() {
	var keys = mutableSetOf<Int>()
	var cnt = IntArray(10001)
	val output = StringBuilder()
	var i = readLine()!!.toInt()
	var tmp:Int

	while (i-- > 0)
	{
		tmp = readLine()!!.toInt()
		keys.add(tmp)
		cnt[tmp]++
	}
	keys.sorted().iterator().forEach {
		while (cnt[it]-- > 0)
			output.append("$it\n")
	 }
	output.deleteCharAt(output.length - 1)
	println(output)
}
