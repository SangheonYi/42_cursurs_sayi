
fun testDeep(c: CharArray) {
    c[0] = 'd'
    println(c)
}

fun main() {
    val alpha = ('a'..'z').toList()
    val c = "im atomic".toCharArray()
    println(c)
    testDeep(c)
    println(c)
}