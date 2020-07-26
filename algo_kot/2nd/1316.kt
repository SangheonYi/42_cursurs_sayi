fun main(args: Array<String>) {
	val wordNum = readLine()!!.toInt()
	var cnt = 0
	for (i in 1 .. wordNum) {
		var word:StringBuilder = StringBuilder(readLine()!!)
		var check:Boolean = true
		var targChar = word[0]
		for (i2 in 0 until word.length) {
			if (targChar == word[i2])
				word[i2] = ' '
			else if (!word.contains(targChar))
			{
				targChar = word[i2]
				word[i2] = ' '
			}
			else
			{
				check = false
				break
			}
		}
		if (check) cnt++
	}
	println(cnt)
}
