fun solution(distance: Int, rocks: IntArray, n: Int): Int {
    var low = 0
    var high = distance
    var mid: Int
    var answer = 0
    var cntRocks: Int
    var forwardRock: Int

    rocks.sort()
    while (low <= high) {
        mid = (low + high) / 2
        cntRocks = 0
        forwardRock = 0
        for (i in rocks) {
            if (i - forwardRock < mid) cntRocks++ else forwardRock = i
            if (cntRocks > n) break
        }
        if (distance - forwardRock < mid) cntRocks++
        if (cntRocks > n) {
            high = mid - 1
            answer = minOf(mid, answer)
        }
        else {
            low = mid + 1
            answer = maxOf(mid, answer)
        }
    }
    return answer
}

fun main() {
    println(solution(16, intArrayOf(4, 8, 11), 2))
}