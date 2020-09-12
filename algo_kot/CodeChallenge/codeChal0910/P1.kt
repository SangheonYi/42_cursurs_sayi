class Solution {
    fun solution(numbers: IntArray): IntArray {
        val answer: IntArray
        val set = mutableSetOf<Int>()

        for ((i1, v1) in numbers.withIndex()) {
            println("$i1 to ${numbers.lastIndex}")
            for (i2 in i1..numbers.lastIndex) {

                if (i1 != i2) {
//                    println("$i1 & $i2")
                    set.add(v1 + numbers[i2])
                }
            }
            println(set)
        }
        answer = set.toIntArray()
        answer.sort()
        return answer
    }
}

fun main() {
    val s = Solution()
    println(s.solution(intArrayOf(2, 1, 3, 4, 1)))
}