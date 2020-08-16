fun main() {
    var a = readLine()!!.toInt()
    var b = readLine()!!.toInt()
    while (b != 0)
    {
        println(a/b)
        println(a%b)
        a = readLine()!!.toInt()
        b = readLine()!!.toInt()
    }
}