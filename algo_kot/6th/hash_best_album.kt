import java.util.*
import kotlin.collections.ArrayList

class Solution {
    class Song (val num: Int, val plays: Int)

    fun solution(genres: Array<String>, plays: IntArray): IntArray {
        val hash = hashMapOf<String, ArrayList<Song>>()
        val genreRank = hashMapOf<String, Int>()
        val answer = arrayListOf<Int>()
        val sortedGenre: List<Pair<String, Int>>

        for (i in 0..genres.lastIndex){
            hash.putIfAbsent(genres[i], arrayListOf())
            hash[genres[i]]!!.add(Song(i, plays[i]))
            genreRank.putIfAbsent(genres[i], 0)
            genreRank[genres[i]] = genreRank[genres[i]]!! + plays[i]
        }
        sortedGenre = genreRank.toList().sortedByDescending { (_, i) -> i }
        sortedGenre.forEach { (k, _) ->
            hash[k]!!.sortByDescending { song -> song.plays }
            answer.add(hash[k]!![0].num)
            if (hash[k]!!.size > 1)
                answer.add(hash[k]!![1].num)
        }
        return answer.toIntArray()
    }
}