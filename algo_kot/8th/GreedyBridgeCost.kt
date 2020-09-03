fun solution(n: Int, costs: Array<IntArray>): Int {
    val sortedCosts = costs.sortedBy { it[2] }
    // weight가 작은 것부터 ASC sorted, 그냥 작은 것부터 추가합니다..
    val visited = mutableSetOf(sortedCosts[0][0])
    // 가장 작은 weight를 가진 간선의 섬 중 하나를 방문한 상태로 시작합니다.
    var answer = 0
    while (visited.size < n) {
        for ((a: Int, b: Int, c: Int) in sortedCosts) {
            if (visited.contains(a) or visited.contains(b)) {
                // 방문 가능한 섬만 방문합니다.
                if (visited.contains(a) and visited.contains(b)) {
                    continue
                    // 이미 방문한 섬 2 곳이기 떄문에 pass 합니다.
                }
                visited.add(a)
                visited.add(b)
                answer += c
                break
                //방문한 섬 목록이 갱신되었기 때문에 break
            }
        }
    }
    return answer
}

fun main() {
    println(solution(4, arrayOf
        (intArrayOf(0,1,1), intArrayOf(0,2,2), intArrayOf(1,2,5),
        intArrayOf(1,3,1), intArrayOf(2,3,8))))
}