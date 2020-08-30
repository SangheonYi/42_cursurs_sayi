class Solution {

    fun solution(n: Int, lost: IntArray, reserve: IntArray): Int {
        val lostArray = (lost.toSet() - reserve.toSet()).toIntArray()
        val able = ArrayList(reserve.toSet() - lost.toSet())
        var answer = n
        var i = 0

        lostArray.sort()
//        println("lostArray.size: ${lostArray.size}, lost.size: ${lost.size}")
        for ((i, v) in lostArray.withIndex())
        {
            when {
                able.contains(v + 1) -> able.remove(v + 1)
                able.contains(v - 1) -> able.remove(v - 1)
                else -> answer--
            }
        }
        return answer
    }
}

fun main() {
    val s = Solution()
    println(s.solution(5,	intArrayOf(2, 4), intArrayOf(1, 3, 5)))
}