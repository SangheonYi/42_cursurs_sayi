class Solution {

    fun solution(n: Int, lost: IntArray, reserve: IntArray): Int {
        val lostArray = (lost.toSet() - reserve.toSet()).toIntArray()
        val able = ArrayList(reserve.toSet() - lost.toSet())
        var answer = n

        lostArray.sort()
        for (v in lostArray)
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
    println(s.solution(4,	intArrayOf(2, 4), intArrayOf(1, 3)))
}