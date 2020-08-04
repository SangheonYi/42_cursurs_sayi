import java.math.BigInteger

fun main(args: Array<String>) {
	val input = readLine()!!.split(' ').map { it.toBigInteger() }
	if (input[1] >= input[2])
	{
		println(-1)
		return
	}

	var quot = input[0] / (input[2] - input[1])
	quot++
	println(quot)
}
