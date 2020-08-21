import java.util.ArrayDeque

class Solution {
    fun solution(priorities: IntArray, location: Int): Int {
        var answer = 0
        var maxPrior: Int
        val doc: ArrayDeque<Int>
        val targetPrior = priorities[location]

        priorities[location] = -1
        doc = ArrayDeque(priorities.toList())
        maxPrior = doc.maxOf { it }
        println(maxPrior)
        while (maxPrior > targetPrior) {
            if (doc.first != maxPrior) {
                doc.add(doc.poll())
                answer++
            } else {
//                doc.poll()
//                println("que: $doc, max: ${doc.maxOf { it }}, polled: ${doc.poll()}, polled que: $doc")
                maxPrior = doc.maxOf { it }
            }
        }
        while (doc.first != -1) {
            doc.add(doc.poll())
            answer++
        }
        return answer + 1
    }
}

fun main() {
    val s = Solution()

    println(s.solution(intArrayOf(2, 1, 3, 2), 1))
}