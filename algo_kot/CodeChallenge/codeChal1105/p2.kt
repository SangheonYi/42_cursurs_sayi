fun bin(s: String, answer: IntArray): String {
    var cnt = 0

    s.forEach { e -> if (e == '1') cnt++ }
    answer[1] += s.length - cnt
    return cnt.toString(2)
}

fun solution(s: String): IntArray {
    val answer = intArrayOf(0, 0)
    var cnt = 0
    var str = s

    while (str != "1") {
        str = bin(str, answer)
        cnt++
    }
    answer[0] = cnt
    return answer
}

fun main() {
    println(solution("110010101001").joinToString(",") )
}