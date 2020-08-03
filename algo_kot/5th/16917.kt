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
		if (input[1] < friedSpicied)
			res += diff * input[1]
		else
			res += diff * friedSpicied
	}
	else if (input[4] < input[3])
	{
		diff = input[3] - input[4]
		res = friedSpicied * input[4]
		if (input[0] < friedSpicied)
			res += diff * input[0]
		else
			res += diff * friedSpicied
	}
	print(res)
}
