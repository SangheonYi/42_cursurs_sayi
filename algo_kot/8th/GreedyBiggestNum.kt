import java.lang.StringBuilder

fun parseBuilder (stringBuilder: StringBuilder) {
    var i = -1

    while (++i < stringBuilder.lastIndex) {
        if (stringBuilder[i] < stringBuilder[i + 1]) {
            stringBuilder.deleteCharAt(i)
            return
        }
    }
    stringBuilder.deleteCharAt(i)
}

class Solution {
    fun solution(number: String, k: Int): String {
        val strBuilder = StringBuilder(number)
        var i = -1

        while (++i < k) parseBuilder(strBuilder)
        return strBuilder.toString()
    }
}

fun main() {
    val s = Solution()
    println(s.solution("9876", 2))
}