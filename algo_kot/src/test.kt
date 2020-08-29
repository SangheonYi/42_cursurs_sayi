import kotlin.random.Random

class TestObj (var a:String = "aaa",
               var b:String = "bbb")
fun testSig(a: Int, b: Int = 0): Int {
    if (a > b) return a - 100
    return b
}

fun main() {
    val tObj = TestObj().apply{
        a = "ccc"
    }
    println(tObj.a)
    println(testSig(1))
    Random.nextInt(100)
}