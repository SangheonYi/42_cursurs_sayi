import java.util.ArrayDeque

fun solution(numbers: IntArray, target: Int): Int {
    var answer = 0
    var polled: Pair<Int, Int>
    var nextIndex: Int
    val que = ArrayDeque<Pair<Int, Int>>()
    //Pair(sum of numbers, last added numbers index)

    que.addLast(Pair(numbers[0], 0))
    que.addLast(Pair(-numbers[0], 0))
    while (que.isNotEmpty()) {
        polled = que.removeFirst()
        if (polled.second == numbers.lastIndex) {
            if (polled.first == target) answer++
            continue
        }
        nextIndex = polled.second + 1
        que.addLast(Pair(polled.first + numbers[nextIndex], nextIndex))
        que.addLast(Pair(polled.first - numbers[nextIndex], nextIndex))
    }
    return answer
}
