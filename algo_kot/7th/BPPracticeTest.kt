class Student {
    val supo1 = intArrayOf(1, 2, 3, 4, 5)
    val supo2 = intArrayOf(2, 1, 2, 3, 2, 4, 2, 5)
    val supo3 = intArrayOf(3, 3, 1, 1, 2, 2, 4, 4, 5, 5)
    var cnt1 = 0
    var cnt2 = 0
    var cnt3 = 0

    fun check (index: Int, ele: Int) {
        if (ele == supo1[index % supo1.size]) cnt1++
        if (ele == supo2[index % supo2.size]) cnt2++
        if (ele == supo3[index % supo3.size]) cnt3++
    }

    fun getAnswer (): IntArray {
        val pocket = intArrayOf(cnt1, cnt2, cnt3)
        val answerList = arrayListOf<Int>()

        for ((index, value) in pocket.withIndex()) {
            if (value == pocket.max()!!) answerList.add(index + 1)
        }
        return answerList.toIntArray()
    }
}
class Solution {
    fun solution(answers: IntArray): IntArray {
        val student = Student()

        for ((index, ele) in answers.withIndex()) student.check(index, ele)

        return student.getAnswer()
    }
}