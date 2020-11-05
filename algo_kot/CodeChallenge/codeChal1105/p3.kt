fun isStar(a: IntArray): Int {
    var cnt = 0

    for ((i, e) in a.withIndex())
        if (i < a.lastIndex && a[i] == a[i + 1]) return -1

    return 1
}

fun solution(a: IntArray): Int {
    var answer: Int = -1

    if (a.size < 4 || a.toSet().size == a.size)
        return 0
    if (a.size % 2 == 0 && isStar(a) > 0) return a.size
    return a.size - 1
}

fun main() {
    println(solution(intArrayOf(-4, -1, -2,-3,-4)))
}