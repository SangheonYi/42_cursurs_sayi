val name: String = "JEROEN"

// A B C D E F G H I J K  L  M  N  O  P  Q  R S T U V W X Y Z
// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 12 11 10 9 8 7 6 5 4 3 2 1
fun solution(name: String): Int {
    var answer = 0
    var current = 0
    val que = ArrayDeque<Int>()
    val nameChars: CharArray = name.toCharArray()

    for (i in 0..nameChars.lastIndex) {
        if (name[i] != 'A') {
            answer += if (name[i] < 'N') name[i] - 'A' else 'Z' - name[i] + 1
            que.add(i)
        }
    }
    if (que.first() == 0) nameChars[que.removeFirst()] = 'A'
    while (que.isNotEmpty()) {
        val left = que.last()
        val right = que.first()
        val lDist = if (left <= current) current - left
        else current + name.length - left
        val rDist = if (right >= current) right - current
        else right + name.length - current

        answer += if (lDist < rDist) lDist else rDist
        current = if (lDist < rDist) que.removeLast() else que.removeFirst()
        nameChars[current] = 'A'
    }
    return answer
}

fun main() {
    print(solution(name)) // 8
}