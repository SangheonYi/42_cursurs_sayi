data class Meat(val w:Int, val h:Int, val o:Int){
	var r: Int = 1

	public fun comparing( b:Meat?): Int
	{
		return (if (w > b!!.w && h > b.h) 1 else 0)
	}
}

fun main(args: Array<String>) {
	var pair = arrayOfNulls<Meat>(readLine()!!.toInt())
	for (i in 0 until pair.size)
	{
		var splited = readLine()!!.split(' ')
		pair[i] = Meat(splited[0].toInt(), splited[1].toInt(), i)
	}
	pair.sortWith(Comparator{a, b ->
		if (a!!.w > b!!.w && a.h > b.h) -1 else 0
	})
	for (i in 0 until pair.size - 1)
	{
		if (pair[i]!!.comparing(pair[i + 1]) > 0)
			pair[i + 1]!!.r = i + 2
		else if(i > 0)
			pair[i + 1]!!.r = pair[i]!!.r
	}
	pair.sortWith(compareBy({it!!.o}))
	for (i in 0 until pair.size - 1)
		print("${pair[i]!!.r} ")
	print("${pair[pair.size - 1]!!.r}")
}
