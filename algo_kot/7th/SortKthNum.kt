import kotlin.collections.ArrayList

class Solution {
    fun solution(array: IntArray, commands: Array<IntArray>): IntArray {
        val answer = IntArray(commands.size) { 0 }
        val list = ArrayList<Int>()

        for (i in 0..commands.lastIndex) {
            for (j in commands[i][0] - 1 until commands[i][1]) list.add(array[j])
            list.sort()
//            println("i:$i, k: ${commands[i][2]}")
            answer[i] = list[commands[i][2] - 1]
            list.clear()
        }
        return answer
    }
}

fun main() {
    val s = Solution().solution(intArrayOf(1, 5, 2, 6, 3, 7, 4), arrayOf(intArrayOf(2, 5, 3), intArrayOf(4, 4, 1), intArrayOf(1, 7, 3)))
    s.forEach { i ->
        println(i)
    }
}
