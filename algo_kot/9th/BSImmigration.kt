fun solution(n: Int, times: IntArray): Long {
    var low: Long = 1
    var high: Long = times.max()!!.toLong() * n.toLong()
    var mid: Long
    var checked: Long
    var answer: Long = high

    while (low <= high) {
        mid = (low + high) / 2
        checked = 0
        for (i in times) {
            checked += mid / i
            if (checked >= n) break
        }
        if (checked >= n) {
            high = mid - 1
            answer = minOf(mid, answer)
        }
        else low = mid + 1
    }
    return answer
}

fun main() {
    println(solution(6, intArrayOf(7, 10)))
}