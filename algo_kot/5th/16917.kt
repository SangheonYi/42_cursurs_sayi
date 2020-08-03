fun main(args: Array<String>) {
	var input = readLine()!!.split(' ').map{it.toInt()}
	var friedSpicied = input[2] + input[2]
	var res = 0
	var diff:Int
	if (input[0] + input[1] < friedSpicied)
		res = input[0] * input[3] + input[1] * input[4]
	else if (input[4] >= input[3])
	{
		diff = input[4] - input[3]
		res = friedSpicied * input[3]
		println("1 input[4] >= input[3] $diff $res")
		if (input[1] < friedSpicied)
		{
			println("res += diff * input[1] ${res + diff * input[1]}")
			res += diff * input[1]
		}
		else
		{
			println("res += diff * friedSpicied ${res + diff * friedSpicied}")
			res += diff * friedSpicied
		}
		println("input[1] < friedSpicied ${input[1] < friedSpicied}")
	}
	else if (input[4] < input[3])
	{
		diff = input[3] - input[4]
		res = friedSpicied * input[4]
		println("2 input[4] < input[3] $diff $res")
		if (input[0] < friedSpicied)
		{
			println("res += diff * input[0] ${res + diff * input[0]}")
			res += diff * input[0]
		}
		else
		{
			println("res += diff * friedSpicied ${res + diff * friedSpicied}")
			res += diff * friedSpicied
		}
		println("input[0] < friedSpicied ${input[0] < friedSpicied}")
	}
	print(res)
}
