import java.util.ArrayDeque

class Solution {
    fun solution(priorities: IntArray, location: Int): Int {
        var answer = 0
        var ele:Int
        val doc = ArrayDeque<Int>()
        val targetPrior = priorities[location]
        var maxPrior = priorities.max()!!

//        priorities[location] = -1
        priorities.mapIndexed { idx, e ->
            doc.add(e)
            if (idx == location) doc.add(-1)
        }
        println("maxPrior: $maxPrior ")
        doc.forEach { i -> print("$i ") }
        println()
        while (maxPrior >= targetPrior) {
            ele = doc.poll()
            if (ele != maxPrior ) {
                if (ele == -1 && targetPrior == maxPrior) break
                doc.add(ele)
            }
            else {
//                doc.poll()
//                println("que: $doc, max: ${doc.maxOf { it }}, polled: ${doc.poll()}, polled que: $doc")
                maxPrior = doc.max()!!
                answer++
            }
        }
        return answer
    }
}

fun main() {
    val s = Solution()

    println(s.solution(intArrayOf(2, 1, 3, 2), 2))
}