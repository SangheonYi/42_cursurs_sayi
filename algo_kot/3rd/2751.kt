fun main() {
	var input = arrayListOf<Int>()
	var i = -1
	val j = readLine()!!.toInt()
	val output = StringBuilder()
	while (++i < j)
		input.add(readLine()!!.toInt())
	input.sort()
	i = -1
	while (++i < j)
	{
		output.append(input[i])
		output.append("\n")
	}
	output.deleteCharAt(output.length - 1)
	println(output)
}
/* 	var input = arrayListOf<Int>()
	var i = -1
	val j = readLine()!!.toInt()
	val output = StringBuilder()
	while (++i < j)
		input.add(readLine()!!.toInt())
	var start = System.currentTimeMillis() // start = 시작시간 - 1970년
	input.sort()
	i = -1
	while (++i < j)
	{
		output.append(input[i])
		output.append("\n")
	}
	output.deleteCharAt(output.length - 1)
	println(output)
	var end = System.currentTimeMillis() // end = 종료시간 - 1970년
	var current = end-start
	println(current)
*/
/* var i = -1
var input = arrayListOf<Int>()
val j = readLine()!!.toInt()
while (++i < j)
	input.add(readLine()!!.toInt())
var start = System.currentTimeMillis() // start = 시작시간 - 1970년
input.sort()
i = -1
while (++i < j)
	println(input[i])
var end = System.currentTimeMillis() // end = 종료시간 - 1970년
var current = end-start
println(current)
*/
/* var i = -1
var sc = Scanner(System.`in`)
var input = arrayListOf<Int>()
while (++i < sc.nextInt())
	input.add(sc.nextInt())
var start = System.currentTimeMillis() // start = 시작시간 - 1970년
input.sort()
i = -1
while (++i < input.size)
	println(input[i])
var end = System.currentTimeMillis() // end = 종료시간 - 1970년
var current = end-start
println(current)
 */
/*var i = -1
var sc = Scanner(System.`in`)
var input = mutableListOf<Int>()
while (++i < sc.nextInt())
	input.add(sc.nextInt())
var start = System.currentTimeMillis() // start = 시작시간 - 1970년
input.sort()
i = -1
while (++i < input.size)
	println(input[i])
var end = System.currentTimeMillis() // end = 종료시간 - 1970년
var current = end-start
println(current)
*/

/* var sc = Scanner(System.`in`)
var input = mutableListOf<Int>()
for (i in 0 until sc.nextInt())
	input.add(sc.nextInt())
var start = System.currentTimeMillis() // start = 시작시간 - 1970년
input.sort()
for (i in 0 until input.size)
	println("${input[i]}")
var end = System.currentTimeMillis() // end = 종료시간 - 1970년
var current = end-start
println(current)*/
/* var sc = Scanner(System.`in`)
	var input = IntArray(sc.nextInt())
	for (i in 0 until input.size)
		input[i] = sc.nextInt()
	input.sort()
	for (i in 0 until input.size)
		println("${input[i]}")
18 */
