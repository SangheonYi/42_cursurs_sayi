import java.util.*
import kotlin.math.min

class Solution {
    fun solution(operations: Array<String>): IntArray {
        var cmd: List<String>
        var value: Int
        val que = PriorityQueue<Int>()

        for (i in operations) {
            cmd = i.split(' ')
            value = cmd[1].toInt()
            when {
                cmd[0] == "I" -> que.add(value)
                que.isNotEmpty() && cmd[0] == "D" ->{
                    when (cmd[1]) {
                        "1" -> {
                            println("remove max: ${que.last()}")
                            que.remove(que.max())
                        }
                        "-1" -> {
                            println("poll min: ${que.peek()}")
                            que.remove(que.min())
                        }
                    }
                }
            }
            que.forEach { print("$it ")}
            println()
        }
        return if (que.isEmpty()) intArrayOf(0, 0)
        else intArrayOf(que.max()!!, que.min()!!)
    }
}
fun main() {
    val s = Solution().solution(arrayOf("I 5", "I 2", "I 3", "I 4", "I 5", "I 6", "I 7", "I 8", "I 9", "I 10", "D 1", "D -1", "D 1", "D -1", "I 1", "I 2", "I 3", "I 4", "I 5", "I 6", "I 7", "I 8", "I 9", "I 10", "D 1", "D -1", "D 1", "D -1"))
    s.forEach { println(it) }
}