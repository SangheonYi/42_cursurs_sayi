import java.util.*

class Solution {
    fun solution(bridge_length: Int, weight: Int, truck_weights: IntArray): Int {
        var answer = 0
        var i = 0
        var weightStat = 0
        val progress = ArrayDeque<Pair<Int, Int>>()

        while (i < truck_weights.size) {
            if (progress.size > 0 && progress.first.second <= answer) {
                weightStat -= progress.first.first
                progress.remove()
            }
            if (i < truck_weights.size && weightStat + truck_weights[i] <= weight) {
                progress.add(Pair(truck_weights[i], answer + bridge_length))
                weightStat += truck_weights[i++]
                answer++
            } else if (progress.size > 0)
                answer = progress.first.second
            if (i > truck_weights.lastIndex)
                answer = progress.last.second
            println("answer: $answer, progress: $progress, i:$i")
        }
        return answer + 1
    }
}

fun main() {
    val s = Solution()

//    println(s.solution(	2, 10, intArrayOf(7, 4, 5, 6)))
    println(s.solution(	100, 100, intArrayOf(10, 10, 10, 10, 10, 10, 10, 10, 10, 10)))
}