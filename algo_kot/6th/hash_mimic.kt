class Solution {

    fun solution(clothes: Array<Array<String>>): Int {
        var answer = 1
        var hash = hashMapOf<String, Int>()

        for (i in 0..clothes.lastIndex){
            hash.putIfAbsent(clothes[i][1], 1)
            hash[clothes[i][1]] = hash[clothes[i][1]]!! + 1
        }
        hash.forEach{k, v -> answer *= v}
        return answer - 1
    }
}