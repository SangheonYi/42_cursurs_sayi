fun sugar(narg: Int){
	var n = narg
	var mod = n % 5
	var cnt:Int = 0

	if (n == 4 || n == 7)
	{
		println(-1)
		return
	}
	if(mod == 2 || mod == 4)
	{
		n -= 9
		cnt += 3
		mod = n % 5
	}
	if(mod == 1 || mod == 3)
		cnt += n / 5 + 1
	else if(mod == 0)
		cnt += n / 5
	println(cnt)
}
fun main(args: Array<String>) {
	for (i in 3 .. 20) {
		print("$i: ")
		sugar(i)
	}

}
