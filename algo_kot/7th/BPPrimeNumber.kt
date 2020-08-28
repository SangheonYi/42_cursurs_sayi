import kotlin.math.sqrt

class Solution {
    private fun isPrime(pref: Int): Boolean {
        val prefRoot = sqrt(pref.toDouble())
        var i = 2

        if (pref == 2) return true
        else if (pref % 2 == 0) return false
        while (++i <= prefRoot)
            if (pref % i == 0) return false
        return true
    }

    fun permutation(pref: String , numbers: String, set: HashSet<Int>) {
        var i = -1

        if (pref != "") set.add(pref.toInt())
        while (++i < numbers.length)
            permutation(pref + numbers[i], numbers.substring(0, i) + numbers.substring(i + 1, numbers.length), set)
    }

    fun solution(numbers: String): Int {
        val set = HashSet<Int>()
        var cnt = 0

        permutation("", numbers, set)
        if (set.contains(1)) set.remove(1)
        for (e in set) {
            if (isPrime(e)) cnt++
        }
        return cnt
    }
}

fun main() {
    val s = Solution()
    println(s.solution("1234"))
}