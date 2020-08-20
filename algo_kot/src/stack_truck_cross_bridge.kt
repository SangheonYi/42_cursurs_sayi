import java.util.*

class Solution {
    fun solution(bridge_length: Int, weight: Int, truck_weights: IntArray): Int {
        var answer = 0
        var i = 0
        var passed = 0
        var weightStat = 0
        val progress = ArrayDeque<Int>()

        while (passed < truck_weights.size)
        {
            if (progress.size == bridge_length && progress.poll() > 0) passed++
            if (i < truck_weights.size && weightStat + truck_weights[i] < weight)
            {
                progress.add(truck_weights[i])
                weightStat += truck_weights[i++]
            }
            else
                progress.add(0)
            answer++
        }
        return answer
    }
}