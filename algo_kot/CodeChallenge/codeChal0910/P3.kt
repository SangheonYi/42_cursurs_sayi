class Solution {
    fun solution(a: IntArray): Int {
        var answer = 0
        var i = 0
        var j: Int
        val min = a.min()
        var right: Boolean
        var leftMin = a[0]

        while (i < a.size){
            right = true
            if (a[i] == min || a[i] == leftMin || i == a.lastIndex) {
                answer++
                i++
                continue
            }
            if (leftMin > a[i]) {
                leftMin = a[i]
                answer++
                i++
                continue
            }
            j = i + 1
            while (j < a.size) {
                if (a[i] > a[j++]) {
                    right = false
                    break
                }
            }
            if (right) answer++
            i++
        }
        return answer
    }
}

fun main() {
    val s = Solution()

    println(s.solution(intArrayOf(-16, 27, 65, -2, 58, -92, -71, -68, -61, -33)))
}