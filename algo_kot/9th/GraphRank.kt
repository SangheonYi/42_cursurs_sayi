class Solution {
    class Player(val win: HashSet<Int> = HashSet(), val lose: HashSet<Int> = HashSet())
    fun solution(n: Int, results: Array<IntArray>): Int {
        var answer = 0
        val playerArray = Array(n + 1) { Player() }
        var tmpSet: HashSet<Int>

        results.forEach {
            playerArray[it[0]].win.add(it[1])
            playerArray[it[1]].lose.add(it[0])
        }
        for (i in 0 until n) {
            for (player in playerArray) {
                tmpSet = HashSet()
                player.win.forEach { tmpSet.addAll(playerArray[it].win) }
                player.win.addAll(tmpSet)
                tmpSet = HashSet()
                player.lose.forEach { tmpSet.addAll(playerArray[it].lose) }
                player.lose.addAll(tmpSet)
            }
        }
        playerArray.forEach { if (it.win.size + it.lose.size == n - 1) answer++}
        return answer
    }
}

fun main() {
    val s = Solution()
    println(s.solution(5,
        arrayOf(intArrayOf(4, 3), intArrayOf(4, 2), intArrayOf(3, 2), intArrayOf(1, 2), intArrayOf(2, 5))))
}