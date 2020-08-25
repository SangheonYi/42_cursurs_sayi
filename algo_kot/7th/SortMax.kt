import java.lang.StringBuilder

class Solution {
    fun solution(numbers: IntArray): String {
        val answer = StringBuilder()

        numbers.toTypedArray()
            .map { e -> e.toString() }
            .sortedWith { o1, o2 -> (o1 + o2).compareTo(o2 + o1) * -1 }
            .forEach { answer.append(it) }
        return if (answer.toString()[0] != '0') answer.toString() else "0"
    }
}

fun main() {
    val s = Solution().solution(intArrayOf(3, 34, 30, 5, 9))
    println("aaa".compareTo("aaa"))
}