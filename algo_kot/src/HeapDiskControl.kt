import java.util.*

class MyJob(val reqTime:Int, val takeTime:Int):Comparable<MyJob> {
    override fun compareTo(other: MyJob): Int = if (this.takeTime < other.takeTime) -1 else 1
}
class Solution {
    fun solution(jobs: Array<IntArray>): Int {
        var answer = 0
        var i = 0
        var cnt = 0
        var time = 0
        val que = PriorityQueue<MyJob>()

        jobs.sortBy { array -> array[0] }
//        jobs.forEach { intArr ->
//            intArr.forEach { ele -> print(ele) }
//            println()
//        }
//        println()
        while (cnt < jobs.size) {
            println("$i ------------")
            for (check in i .. jobs.lastIndex) {
                if (check < jobs.size && time >= jobs[check][0]) {
//                    print("${i}th add time: $time que: ")
//                    que.forEach {e -> print(e.reqTime)
//                        print(e.takeTime)
//                    }
//                    print(" jobs[$i]: ")
//                    jobs[i].forEach { e -> print(e) }
//                    println()
                    que.offer(MyJob(jobs[check][0], jobs[check][1]))
                    i++
                }
                else break
            }
            if (que.isNotEmpty()) {
//                print("${i}th poll time: $time que: ")
//                que.forEach {e -> print(e.reqTime)
//                    print(e.takeTime)
//                }
//                println()
                time += que.peek().takeTime
                answer += time - que.poll().reqTime
                cnt++
            }
            else  time = jobs[i][0]
        }
        return answer / jobs.size
    }
}

fun main() {
    val s = Solution().solution(arrayOf(intArrayOf(0, 3), intArrayOf(1, 9), intArrayOf(2, 6)))
    println("return: $s")
}