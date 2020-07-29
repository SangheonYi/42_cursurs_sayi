fun main(args: Array<String>) {
	val n = readLine()!!.toInt()
	val edge = 4 * n - 3
	var i = -1
	var outPut = arrayListOf<String>()
	var even = StringBuilder()
	var odd = StringBuilder()

	while (++i < edge)
	{
		even.append('*')
		odd.append(' ')
	}
	i = -1
	while (++i <= edge / 2)
	{
		if (i % 2 == 0)
		{
			if (i % 2 == 1)
			{
				even.setCharAt(i - 1, ' ')
				even.setCharAt(even.lastIndex - (i - 1), ' ')
			}
			outPut.add(even.toString())
			//출력용 builder도 새로 만들어 주자
		}
		else
		{
			if (i % 2 == 1)
			{
				odd.setCharAt(i - 1, '*')
				odd.setCharAt(odd.lastIndex - (i - 1), '*')
			}
			outPut.add(odd.toString())
		}
	}
	println(buildLine())
}
