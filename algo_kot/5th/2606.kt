import java.io.*
import java.lang.StringBuilder
import java.util.*
import kotlin.collections.ArrayList

fun readInts() = readLine()!!.split(' ').map{ it.toInt() }

fun BFS(graph:MutableList<ArrayList<Int>>, nodes:Int):Int
{
    val que = ArrayDeque<Int>()
    val check = BooleanArray(nodes + 1) { a -> false }
    var visiting:Int
    var i:Int
    var cnt = -1

    que.add(1)
    while (!que.isEmpty())
    {
        visiting = que.poll()
        if (!check[visiting])
        {
            check[visiting] = true
            cnt++
        }
        i = -1
        while (++i < graph[visiting].size)
        {
            if (!check[graph[visiting][i]])
                que.add(graph[visiting][i])
        }
    }
    return cnt
}
fun main() {
    val nodes = readLine()!!.toInt()
    val line = readLine()!!.toInt()
    val graph = MutableList<ArrayList<Int>>(nodes + 1, {i -> ArrayList() })
    var i = -1
    var tmpInts:List<Int>

    while (++i < line)
    {
        tmpInts = readInts()
        graph[tmpInts[0]].add(tmpInts[1])
        graph[tmpInts[1]].add(tmpInts[0])
    }
    graph.forEach { a -> a.sort() }
    println(BFS(graph, nodes))
}
