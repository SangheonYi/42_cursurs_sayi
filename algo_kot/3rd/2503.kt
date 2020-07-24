data class BaseBall(val num:Int, val strike:Int, val ball:Int)
{
	val set:Set<Int> = setOf<Int>(num / 100, (num / 10) % 10, num % 10)
	val sum = strike + ball
}

fun main(args: Array<String>) {
	var bB = arrayOfNulls<BaseBall>(readLine()!!.toInt())
	var input:List<String>
	var guess:Set<Int> = mutableSetOf()
	var young:Array<Int> = arrayOf(3)
	for (i in 0 until bB.size) {
		input = readLine()!!.split(" ")
		bB[i] = BaseBall(input[0].toInt(), input[1].toInt(), input[2].toInt())
	}
	for (i in 0 until bB.size) {
		for (j in i until bB.size) {
			if (i != j)
			{
				if(bB[i]!!.sum == 3)
				else if(bB[i]!!.sum == 2 && bB[j]!!.sum == 2 )
				{
					var tmp = bB[i]!!.set.intersect(bB[j]!!.set)
					guess.union(tmp)
					guess.subtract(bB[i]!!.set.union(bB[j]!!.set).subtract(tmp))
				}
				else if()
					print("${bB[i]!!.strike + bB[i]!!.ball} ${bB[j]!!.strike + bB[j]!!.ball}")
					println(bB[i]!!.set.intersect(bB[j]!!.set))
			}
		}
	}
	println(guess.size)
}
