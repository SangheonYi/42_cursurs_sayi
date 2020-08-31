import kotlin.random.Random

fun testSig(set: HashSet<Int>, b: Int = 0): Int {
    set.add(b)
    return set.size
}

fun main() {
    val set = HashSet<Int>()
    testSig(set)
    testSig(set, 5)
    testSig(set, 10)
    set.forEach {e ->
        print(e)
    }
}