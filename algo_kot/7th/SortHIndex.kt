class Solution {
    fun solution(citations: IntArray): Int {
        var h = 1

        citations.sort()
        for (i in citations.lastIndex downTo 0) {
            if (citations[i] >= h &&
                (i == 0 || (i > 0 && citations[i - 1] <= h))) return h
            h++
        }
        return 0
    }
}