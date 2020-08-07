import java.io.*;
import java.util.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
	var input = IntArray(10001)
	var i = -1
	var j = readLine()!!.toInt()
	val output = StringBuilder()
	while (++i < j)
		input[readLine()!!.toInt()]++
	i = 0
	while (++i < input.size && j > 0)
	{
		while(input[i]-- > 0)
		{
			output.append("$i\n")
			j--
		}
	}
	println(output)
}
