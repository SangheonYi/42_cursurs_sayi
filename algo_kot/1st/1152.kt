fun main() {
	val splited = readLine()!!.split(" ")
	var cnt = 0
	for (i in 0 until splited.size) {
		if (splited[i].length > 0)
			cnt++
	}
	print(cnt)
}
