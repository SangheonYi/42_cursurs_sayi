import java.util.ArrayDeque

fun networkBFS(que: ArrayDeque<Int>, computers: Array<IntArray>, remain: HashSet<Int>) {
    var polled: Int
    val lastIndex = computers.lastIndex
    var element: Int

    while (que.isNotEmpty()) {
        polled = que.poll()
        remain.remove(polled)
        for (j in 0..lastIndex) {
            element = computers[polled][j]
            if (element == 1 && remain.contains(j)) que.add(j)
        }
    }
}
fun solution(n: Int, computers: Array<IntArray>): Int {
    var answer = 0
    val que = ArrayDeque<Int>()
    val remain = (0 until n).toHashSet()

    while (remain.isNotEmpty()) {
        que.add(remain.first())
        //BFS
        networkBFS(que, computers, remain)
        answer++
        //add next network root node
    }
    return answer
}
fun main() {
    val a = arrayOf(
//4, [[1, 0, 0, 1], [0, 1, 1, 0], [0, 1, 1, 0], [1, 1, 0, 1]]
        intArrayOf(1, 0, 0, 1),//0
        intArrayOf(0, 1, 1, 1),//1
        intArrayOf(0, 1, 1, 0),//2
        intArrayOf(1, 1, 0, 1)//3
//        intArrayOf(1, 1, 0, 0, 0, 0, 0, 0, 0, 0),//0
//        intArrayOf(1, 1, 1, 0, 0, 0, 0, 0, 0, 0),//1
//        intArrayOf(0, 1, 1, 0, 0, 0, 0, 0, 0, 0),//2
//        intArrayOf(0, 0, 0, 1, 1, 0, 0, 0, 0, 0),//3
//        intArrayOf(0, 0, 0, 1, 1, 0, 0, 0, 0, 0),//4
//        intArrayOf(0, 0, 0, 0, 0, 1, 1, 1, 0, 0),//5
//        intArrayOf(0, 0, 0, 0, 0, 1, 1, 0, 1, 0),//6
//        intArrayOf(0, 0, 0, 0, 0, 1, 0, 1, 1, 0),//7
//        intArrayOf(0, 0, 0, 0, 0, 0, 1, 1, 1, 0),//8
//        intArrayOf(0, 0, 0, 0, 0, 0, 0, 0, 0, 1)//9
    )
    println(solution(4, a))
}