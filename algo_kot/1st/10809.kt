fun main() {
	var arg:String = readLine()!!
	for (i in 'a' .. 'z') {
		print(arg.indexOf(i))
		if (i != 'z') print(" ")
	}
}
