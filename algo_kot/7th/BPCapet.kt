class Solution {
    fun solution(brown: Int, yellow: Int): IntArray {
        var x = 3
        var y = 3

        while (x * y != brown + yellow ||
            brown != 2 * x + 2* y - 4 ||
            yellow != (x - 2) * (y - 2)) {
            if (x > y) y++
            else {
                y = 3
                x++
            }
        }
        return intArrayOf(x, y)
    }
}