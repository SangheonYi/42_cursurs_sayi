
fun main() {
    val foo = "sayi".toHashSet()
    val foo2 = "yi".toHashSet()
    (foo - foo2).forEach {
        println(it)
    }
}