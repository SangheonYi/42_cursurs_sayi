class Solution {
    fun solution(progresses: IntArray, speeds: IntArray): IntArray {
        val answer = arrayListOf(1)
        val days = IntArray(progresses.size)
        var dDay:Int

        days[0] = (100 - progresses[0]) / speeds[0]
        if ((100 - progresses[0]) % speeds[0] > 0) days[0]++
        dDay = days[0]
        for (i in 1 .. progresses.lastIndex)
        {
            days[i] = (100 - progresses[i]) / speeds[i]
            if ((100 - progresses[i]) % speeds[i] > 0) days[i]++
            if (dDay >= days[i])
                answer[answer.lastIndex]++
            else
            {
                dDay = days[i]
                answer.add(1)
            }
        }
        return answer.toIntArray()
    }
}