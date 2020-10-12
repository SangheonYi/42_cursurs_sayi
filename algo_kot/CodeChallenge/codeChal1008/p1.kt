fun threePower(expo: Int): Int {
    var ret = 1

    for (i in 0 until expo) ret *= 3
    return ret
}

fun solution(n: Int): Int {
        val converted = n.toString(3)
        var answer = 0
        var i = -1

        while (++i < converted.length) {
            val tmp = converted[i].toInt() - 48

            if (tmp != 0) answer += tmp * threePower(i)
        }
        return answer
    }

fun main() {
    println(solution(45))
}