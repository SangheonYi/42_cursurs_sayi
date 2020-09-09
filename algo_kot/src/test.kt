
fun main() {
    val src1 = arrayListOf(arrayOf("ICN", "A"), arrayOf("ICN", "B"), arrayOf("B", "ICN"))
    val src2 = arrayListOf(arrayOf("ICN", "A"), arrayOf("ICN", "B"), arrayOf("B", "ICN"))
    val src3 = arrayListOf(arrayOf("ICN", "A"), arrayOf("ICN", "B"), arrayOf("B", "ICN"))
    val src4 = arrayListOf(arrayOf("ICN", "A"), arrayOf("ICN", "B"), arrayOf("B", "ICN"))
    val copiedAddAll = ArrayList<Array<String>>()
    val copiedForEachAdd = ArrayList<Array<String>>()
    val copiedConstructWithSrc = ArrayList<Array<String>>(src3)
    val copiedForEachAddCopyOf = ArrayList<Array<String>>()

    copiedAddAll.addAll(src1) // addAll
    src2.forEach { copiedForEachAdd.add(it) } // for each add
    src4.forEach { copiedForEachAddCopyOf.add(it.copyOf()) }// for each add copy of

    copiedAddAll[0][0] = "changed"
    copiedForEachAdd[0][0] = "changed"
    copiedConstructWithSrc[0][0] = "changed"
    copiedForEachAddCopyOf[0][0] = "changed"

    println("Shallow copy")
    println("Add all")
    print("src: ")
    src1.forEach { print(it.contentToString()) }
    print("\ncopied: ")
    copiedAddAll.forEach { print(it.contentToString()) }
    println("\n\nFor each add")
    print("src: ")
    src2.forEach { print(it.contentToString()) }
    print("\ncopied: ")
    copiedForEachAdd.forEach { print(it.contentToString()) }
    println("\n\nConstruct with src")
    print("src: ")
    src3.forEach { print(it.contentToString()) }
    print("\ncopied: ")
    copiedConstructWithSrc.forEach { print(it.contentToString()) }
    println("\n\nDeep copy")
    println("For each add copy of")
    print("src: ")
    src4.forEach { print(it.contentToString()) }
    print("\ncopied: ")
    copiedForEachAddCopyOf.forEach { print(it.contentToString()) }
}