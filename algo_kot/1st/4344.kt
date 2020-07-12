fun readInts() = readLine()!!.split(' ').map { it.toInt() }
fun main(args: Array<String>){
	var lineNum:Int = readLine()!!.toInt()

	for (i in 1..lineNum) {
		val point = readInts()
		var avr:Double = (point.sum() - point[0]).toDouble()/point[0]
		var upper:Double = 0.toDouble()
		// println("upper:$upper avr:$avr point:$point")
		for (i2 in 1 until point.size) {
			// println("i2:$i2")
			if (point[i2] > avr)
			{
				// println("${point[i2]} > $avr")
				upper++
			}
		}
		println("%.3f%%".format(upper * 100 / point[0]))
	}
}
