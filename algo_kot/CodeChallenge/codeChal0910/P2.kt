class Solution {
    fun solution(n: Int): IntArray {
        val blockNum = n * (n + 1) / 2
        val answer = IntArray(blockNum)
        val piramid = Array(n) {i: Int -> IntArray(i + 1) }
        var depth = 0
        var row = 0
        var col = 0
        var i = 0
//        println(blockNum)
        while (i < blockNum) {
//            println("down")
            while (row < n - depth) piramid[row++][col] = ++i
            if (i >= blockNum) break
            row--
            col++
//            println("bot")
            while (col <= row - depth) piramid[row][col++] = ++i
//            piramid.forEach { println(it.contentToString()) }
//            println("i = $i & $blockNum")
            if (i >= blockNum) break
            col -= 2
            row --
            depth++
//            println("up")
            while (col > depth) piramid[row--][col--] = ++i
//            piramid.forEach { println(it.contentToString()) }
        }
        i = -1
        piramid.forEach { for (ele in it) answer[++i] = ele }
        return answer
    }
}

fun main() {
    val s = Solution()
    s.solution(5)
}