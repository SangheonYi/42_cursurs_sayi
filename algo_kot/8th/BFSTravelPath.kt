import java.util.ArrayDeque

class Travller(var curAirport: String, var path: ArrayList<String>, val tickets: ArrayList<Pair<String, String>>)

fun solution(tickets: Array<Array<String>>): Array<String> {
    var path = arrayListOf("")
    val worldMap = HashMap<String, ArrayList<String>>()
    val que = ArrayDeque<Travller>()
    var depart: String
    var remainTickets = arrayListOf<Pair<String, String>>()

    tickets.forEach {
        worldMap.putIfAbsent(it[0], ArrayList())
        worldMap[it[0]]!!.add(it[1])
        remainTickets.add(Pair(it[0], it[1]))
    }
    worldMap.forEach { if (it.value.size > 1) it.value.sort() }
    que.add(Travller("ICN", arrayListOf("ICN"), remainTickets))
    while (que.isNotEmpty()) {
        depart = que.peek().curAirport
        if (worldMap.containsKey(depart)) {
            worldMap[depart]!!.forEach {
                val nextTicket = Pair(depart, it)

                path = ArrayList(que.peek().path)
                remainTickets = ArrayList(que.peek().tickets)
                if (remainTickets.contains(nextTicket)) {
                    path.add(it)
                    if (path.size == tickets.size + 1) return path.toTypedArray()
                    remainTickets.remove(nextTicket)
                    que.add(Travller(path.last(), path, remainTickets))
                }
            }
        }
        que.poll()
    }
    return path.toTypedArray()
}

fun main() {
    solution(arrayOf(arrayOf("ICN", "A"), arrayOf("ICN", "B"), arrayOf("B", "ICN"),
    )).forEach { println(it) }
}