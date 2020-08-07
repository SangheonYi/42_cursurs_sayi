fun increment(map: MutableMap<Int, Int>, key: Int) {
	map.putIfAbsent(key, 0)
	map[key] = map[key]!! + 1
}

fun main() {
	var mMap = mutableMapOf<Int, Int>()
	var i = -1
	var j = readLine()!!.toInt()
	val output = StringBuilder()
	while (++i < j)
		increment(mMap, readLine()!!.toInt())
	var iter = mMap.keys.iterator()
	iter.forEach {
		while(mMap[it]!! > 0)
		{
			output.append("$it\n")
			mMap[it] = mMap[it]!! - 1
		}
	 }
	output.deleteCharAt(output.length - 1)
	println(output)
}
