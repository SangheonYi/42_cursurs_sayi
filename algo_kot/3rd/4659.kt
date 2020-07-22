fun isAeiou(c:Char):Boolean = if(c == 'a' || c == 'e' || c == 'i'
	|| c == 'o' || c == 'u') true else false
fun main() {
	var repeated:Int = 0
	var acceptable:Boolean
	var args = ArrayList<String>()
	args.add(readLine()!!)
	while(!args[repeated++].equals("end"))
		args.add(readLine()!!)
	for (i2 in 0 until args.size - 1) {
		repeated = 0
		acceptable = false
		for (i in 0 until args[i2].length) {
			if(isAeiou(args[i2][i]))
				acceptable = true
			if(i > 0 && isAeiou(args[i2][i - 1]) != isAeiou(args[i2][i]))
				repeated = 0
			repeated++
			if(repeated > 2 ||
			(i > 0 && args[i2][i] == args[i2][i - 1] &&
			args[i2][i] != 'e' && args[i2][i] != 'o'))
			{
				acceptable = false
				break ;
			}
		}
		if (acceptable)
			println("<${args[i2]}> is acceptable.")
		else
			println("<${args[i2]}> is not acceptable.")
	}
}
