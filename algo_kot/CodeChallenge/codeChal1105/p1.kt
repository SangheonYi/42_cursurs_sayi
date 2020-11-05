fun solution(a: IntArray, b: IntArray): Int {
    var answer = 0
    var i = -1

    while (++i < a.size) {
        answer += a[i] * b[i]
    }
    return answer
}

fun main() {
    println(solution(intArrayOf(1,2,3,4), intArrayOf(-3,-1,0,2)))
}