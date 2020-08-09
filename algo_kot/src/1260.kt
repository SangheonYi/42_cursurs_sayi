import java.io.*
import java.lang.StringBuilder
import java.util.*
import kotlin.collections.ArrayList

fun readInts() = readLine()!!.split(' ').map{ it.toInt() }

fun DFS(graph:MutableList<ArrayList<Int>>, attribute:List<Int>, out:StringBuilder) {
    val stack = ArrayDeque<Int>()
    val check = BooleanArray(attribute[0] + 1) { a -> false }
    var visiting:Int
    var i:Int

    stack.push(attribute[2])
    while (!stack.isEmpty())
    {
        visiting = stack.peek()
        if (!check[visiting])
        {
            out.append("${visiting} ")
            check[visiting] = true
//            println(stack)
        }
        stack.pop()
        i = graph[visiting].lastIndex
//        println("visiting: $visiting, i: $i")
        while (i >= 0)
        {
            if (!check[graph[visiting][i]])
            {
                stack.push(graph[visiting][i])
                println("pushed: ${graph[visiting][i]}")
            }
            i--
        }
    }
}

fun BFS(graph:MutableList<ArrayList<Int>>, attribute:List<Int>, out:StringBuilder)
{
    val que = ArrayDeque<Int>()
    val check = BooleanArray(attribute[0] + 1) { a -> false }
    var visiting:Int
    var i:Int

    que.add(attribute[2])
    while (!que.isEmpty())
    {
        visiting = que.poll()
        if (!check[visiting])
        {
            out.append("${visiting} ")
            check[visiting] = true
            println(que)
        }
        que.pop()
        i = graph[visiting].lastIndex
        println("visiting: $visiting, i: $i")
        while (i >= 0)
        {
            if (!check[graph[visiting][i]])
            {
                que.push(graph[visiting][i])
                println("pushed: ${graph[visiting][i]}")
            }
            i--
        }
    }
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val out = StringBuilder()
    val attribute = readInts()
    val graph = MutableList<ArrayList<Int>>(attribute[0] + 1, {i -> ArrayList() })
    var i = -1
    var tmpInts:List<Int>

    while (++i < attribute[1])
    {
        tmpInts = readInts()
        graph[tmpInts[0]].add(tmpInts[1])
        graph[tmpInts[1]].add(tmpInts[0])
    }
    graph.forEach { a -> a.sort() }
    DFS(graph, attribute, out)
    BFS(graph, attribute, out)
    println(out)
}
