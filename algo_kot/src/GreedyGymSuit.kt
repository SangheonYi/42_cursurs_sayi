class Solution {

    fun solution(n: Int, lost: IntArray, reserve: IntArray): Int {
        var answer = n - lost.size
        var i = 0
        val lostSet = HashSet<Int>()
        val able = arrayListOf<Int>()

        lost.forEach { e -> lostSet.add(e) }
        reserve.forEach { e ->
            if (lostSet.contains(e)) {
                lostSet.remove(e)
                answer++
            }
            else able.add(e)
        }
        able.sort()
        println("lostSet.size: ${lostSet.size}, lost.size: ${lost.size}")
        while (able.isNotEmpty())
        {
            var left = false
            var right = false
            val e = able[i]

            if (lostSet.contains(e - 1)) left = true
            if (lostSet.contains(e + 1)) right = true
            if ((left && right && !able.contains(e + 2)) || (!left && right)) {
                lostSet.remove(e + 1)
                able.remove(e)
                answer++
            }
            else if ((left && right && !able.contains(e - 2)) || (left && !right)) {
                lostSet.remove(e - 1)
                able.remove(e)
                answer++
            }
            else if (!left && !right)
                able.remove(e)
            if (i < able.lastIndex) i++ else i = 0
        }
        return answer
    }
}

fun main() {
    val s = Solution()
    println(s.solution(5,	intArrayOf(2, 4), intArrayOf(1, 3, 5)))
}