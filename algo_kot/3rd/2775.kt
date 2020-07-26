fun main(args: Array<String>) {
	var mat = Array<IntArray>(15, {IntArray(15)})
	for (i in 0 until 15) {
		mat[0][i] = i + 1
		mat[i][0] = 1
	}
	for (i in 1 until 15) {
		for (j in 1 until 15)
			mat[i][j] = mat[i - 1][j] + mat[i][j-1]
	}
	var k:Int
	var n:Int
	for (i in 1 .. readLine()!!.toInt())
	{
		k = readLine()!!.toInt()
		n = readLine()!!.toInt()
		println(mat[k][n - 1])
	}
}
