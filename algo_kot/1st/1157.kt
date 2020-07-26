fun main() {
	val s = readLine()!!
	var log = MutableList<Int>(26, {i -> 0})

	for (i in 0 until s.length)
		log[s[i].toUpperCase() - 'A']++
	val max = log.max()
	val maxIndex:Int = log.indexOf(max)
	log[maxIndex] = 0
	if (max != log.max())
		println("${(maxIndex + 'A'.toInt()).toChar()}")
	else
		println('?')
}
