
open class Person(val name: String) {
    open fun introduce() {
        println("i am $name")
    }
}

class Foo(name: String): Person(name) {
//    override fun introduce() {
//        print("i am foo")
//    }
}

fun main() {
    val foo = Foo("sayi")
    foo.introduce()
}