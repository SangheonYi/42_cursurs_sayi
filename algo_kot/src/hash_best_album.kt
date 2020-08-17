class Solution {
    fun solution(genres: Array<String>, plays: IntArray): IntArray {
        val hash = hashMapOf<String, IntArray>()

        for (i in 0..genres.lastIndex){
            hash.putIfAbsent(genres[i], intArrayOf(i, i))
            if (plays[hash[genres[i]]!![1]] < plays[i])
            {
                if (plays[hash[genres[i]]!![0]] < plays[i]) {
                    hash[genres[i]]!![1] = hash[genres[i]]!![0]
                    hash[genres[i]]!![0] = i
                }
                else
                    hash[genres[i]]!![1] = i
            }
        }
        val answer = IntArray(hash.size * 2)
        var i = 0
        hash.forEach{k, v ->
            answer[i++] = v[0]
            answer[i++] = v[1]
        }
        return answer
    }
}