fun toInts() = readLine()!!.split(' ').map { it.toDouble() }
fun main(args: Array<String>) {
	var quotient = mutableListOf<Double>()
	var balance = toInts().toMutableList()
	var rate = toInts().toMutableList()
	var min:Double

	quotient.add(balance[0] / rate[0])
	quotient.add(balance[1] / rate[1])
	quotient.add(balance[2] / rate[2])
	min = quotient.min()!!

	println("${balance[0] - min * rate[0]} ${balance[1] - min * rate[1]} ${balance[2] - min * rate[2]}")
}
