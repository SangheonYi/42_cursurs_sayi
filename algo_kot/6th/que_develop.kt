class Solution {
    fun solution(progresses: IntArray, speeds: IntArray): IntArray {
        val answer = arrayListOf(1)
        val days = IntArray(progresses.size)
        var dDay:Int

        if ((100 - progresses[0]) % speeds[0] > 0)
            days[0] = (100 - progresses[0]) / speeds[0] + 1
        else
            days[0] = (100 - progresses[0]) / speeds[0]
        dDay = days[0]
        for (i in 1 .. progresses.lastIndex)
        {
            days[i] = (100 - progresses[i]) / speeds[i]
            if ((100 - progresses[i]) % speeds[i] > 0)
                days[i] = (100 - progresses[i]) / speeds[i] + 1
            else
                days[i] = (100 - progresses[i]) / speeds[i]
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