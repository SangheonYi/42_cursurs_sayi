fun splitCheck(arr: Array<IntArray>, scale: Int, index: Int) {

}
fun solution(arr: Array<IntArray>): IntArray {
    var answer: IntArray = intArrayOf()
    var scale = arr.size

    while (scale > 0) {
        var sqrLast = arr.size / scale

        while (arr.size > sqrLast) {

            sqrLast += scale
        }
        scale /= 2
    }
    return answer
}

fun main() {
    println(solution())
}