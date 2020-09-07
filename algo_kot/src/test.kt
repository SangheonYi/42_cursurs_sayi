
fun main() {
    val foo = arrayListOf(arrayOf("ICN", "A"), arrayOf("ICN", "B"), arrayOf("B", "ICN"))
//    val foo = arrayOf(arrayOf("ICN", "A"), arrayOf("ICN", "B"), arrayOf("B", "ICN"))
    val hs = ArrayList<Array<String>>()
//    for (i in 0..foo.lastIndex) { hs.add( foo[i].copyOf()) }
//    hs[0] = arrayOf("ICN", "B")
    hs.addAll(foo)
    hs[0][0] = "chan"
    foo.forEach { print(it.contentToString()) }
    println()
    hs.forEach { print(it.contentToString()) }
//    array DeeptoString으로 알맹이 출력 쉽다.
//    println(foo.contentToString())
//    println(foo.contentDeepToString())
}