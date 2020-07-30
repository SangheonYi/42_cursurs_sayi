// v = 299792458 * sqr(1 - pow(tb / ta))
// until under 3
// in
//10.5 5.25
// 5 1
// 0 0
// out
// 0.866
// 0.980
import kotlin.math.pow
fun main(args: Array<String>) {
	var input = readLine()!!.split(' ').map { it.toDouble() }
	var tatb = mutableListOf<Double>(input[0], input[1])
	while (tatb[0] != 0.0 && tatb[1] != 0.0)
	{
		println("%.3f".format((1 - (tatb[1] / tatb[0]).pow(2)).pow(1 / 2.0)))
		input = readLine()!!.split(' ').map { it.toDouble() }
		tatb[0] = input[0]
		tatb[1] = input[1]
	}
}
