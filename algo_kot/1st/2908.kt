fun main() {
	var number = readLine()!!.split(" ")
	if (number[0].reversed().toInt() > number[1].reversed().toInt())
		print(number[0].reversed())
	else
		print(number[1].reversed())
}
