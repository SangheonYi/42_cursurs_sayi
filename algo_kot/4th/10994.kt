fun main(args: Array<String>) {
	val n = readLine()!!.toInt()
	val edge = 4 * n - 3
	var i = -1
	var outPut = arrayListOf<String>()
	var even = StringBuilder()
	var odd = StringBuilder()
	// var result = StringBuilder()

	while (++i < edge)
	{
		even.append('*')
		odd.append(' ')
	}
	outPut.add(even.toString())
	i = 0
	while (++i <= edge / 2)
	{
		if (i % 2 == 0)
		{
			even.setCharAt(i - 1, ' ')
			even.setCharAt(even.lastIndex - (i - 1), ' ')
			outPut.add(even.toString())
		}
		else
		{
			odd.setCharAt(i - 1, '*')
			odd.setCharAt(odd.lastIndex - (i - 1), '*')
			outPut.add(odd.toString())
		}
	}
	i = -1
	while(++i < outPut.size)
	{
		print("$i: ")
		println(outPut[i])
	}
	i = outPut.size - 1
	while(--i >= 0)
	{
		print("$i: ")
		println(outPut[i])
	}
}
