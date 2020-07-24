data class BaseBall(val num:Int, val strike:Int, val ball:Int)
{
	val first = num / 100
	val second = (num / 10) % 10
	val third = num % 10
	val set:Set<Int> = setOf<Int>(first, second, third)
	val sum = strike + ball
}
fun checkBaseBall(bB:Array<BaseBall?>, i:Int, j:Int, k:Int):Boolean
{
	for (l in 0 until bB.size) {
		var tmp = bB[l]!!
		var strikeCnt = 0
		var ballCnt = 0
		if (i == tmp.first)
			strikeCnt++
		else if (tmp.set.contains(i))
			ballCnt++
		if (j == tmp.second)
			strikeCnt++
		else if (tmp.set.contains(j))
			ballCnt++
		if (k == tmp.third)
			strikeCnt++
		else if (tmp.set.contains(k))
			ballCnt++
		if (tmp.strike != strikeCnt || tmp.ball != ballCnt)
			return false
	}
	return true
}
fun main(args: Array<String>) {
	var bB:Array<BaseBall?> = arrayOfNulls<BaseBall>(readLine()!!.toInt())
	var input:List<String>
	var cnt = 0

	for (i in 0 until bB.size) {
		input = readLine()!!.split(" ")
		bB[i] = BaseBall(input[0].toInt(), input[1].toInt(), input[2].toInt())
	}
	for (i in 1 .. 9) {
		for (j in 1 .. 9) {
			if (i == j) continue
			for (k in 1 .. 9) {
				if (k == i || k == j) continue
				if (checkBaseBall(bB, i, j, k))
					cnt++
			}
		}
	}
	println(cnt)
}
