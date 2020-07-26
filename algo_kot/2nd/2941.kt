fun main(args: Array<String>) {
	val croatia = arrayOf("c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=")
	var input = readLine()!!
	for (i in croatia)
		input = input.replace(i, " ")
	println(input.length)
}
