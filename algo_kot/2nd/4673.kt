fun getDnum(num:Int):Int
{
	var tmpNum:Int = num
	var dn:Int = num
	var divided:Int
	var moded:Int
	while(true)
	{
		divided = tmpNum / 10
		moded = tmpNum % 10
		if (divided != 0 || moded != 0)
		{
			dn += moded
			tmpNum = divided
			continue
		}
		break
	}
	return dn
}
fun main(args: Array<String>) {
	var	log:BooleanArray = BooleanArray(10000, {i->true})
	var	dnum:Int
	for (i in 1 until log.size) {
		dnum = getDnum(i)
		if(dnum < 10000)
			log[dnum] = false
		if(log[i])
			println(i)
	}
}
