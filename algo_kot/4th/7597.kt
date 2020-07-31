fun main(args: Array<String>) {
	var i:Int
	var winA:Int
	var winB:Int
	var cntA:Int
	var cntB:Int
	var input = readLine()

	while(!input.equals("#"))
	{
		i = -1
		winA = 0
		winB = 0
		cntA = 0
		cntB = 0
		while(++i < input!!.length)
		{
			if (input[i] == 'A') cntA++ else cntB++
			if (cntA > 3 && cntA - cntB > 1)
			{
				// println("A$i cntA $cntA cntB $cntB")
				winA++
				cntA = 0
				cntB = 0
			}
			else if (cntB > 3 && cntB - cntA > 1)
			{
				// println("B$i cntA $cntA cntB $cntB")
				cntA = 0
				cntB = 0
				winB++
			}
		}
		println("A $winA B $winB")
		input = readLine()
	}
}
