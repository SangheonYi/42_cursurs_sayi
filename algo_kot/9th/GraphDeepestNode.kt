import java.util.ArrayDeque

class Solution {
    class Note(val node: Int, var depth:Int = 0)

    fun solution(n: Int, edge: Array<IntArray>): Int {
        val graph = Array<ArrayList<Int>>(n + 1) { ArrayList() }
        val que = ArrayDeque<Note>()
        val dist = IntArray(n + 1) { -1 }
        var currentNote : Note
        var maxDepth = 1
        var answer = 0

        edge.forEach {
            graph[it[0]].add(it[1])
            graph[it[1]].add(it[0])
        }
        que.add(Note(1))
        dist[1] = 0
        while (que.isNotEmpty()){
            currentNote = que.poll()
            for (i in graph[currentNote.node]) {
                if (dist[i] < 0) {
                    dist[i] = currentNote.depth + 1
                    que.add(Note(i, currentNote.depth + 1))
                }
            }
            if (maxDepth < currentNote.depth) {
                answer = 1
                maxDepth = currentNote.depth
            }
            else if (maxDepth == currentNote.depth) answer++
        }
        println(maxDepth)
        return answer
    }
}

fun main() {
    val s = Solution()
    println(s.solution(6, arrayOf(intArrayOf(1, 2))))
}