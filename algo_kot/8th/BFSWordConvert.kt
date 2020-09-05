import java.util.ArrayDeque

class Solution {
    class Word(val word: String) {
        var visit = false
        var diffCnt = 0
    }

    fun compareWord(begin: Word, word: Word): Int {
        var ret = 0

        for ((i, v) in begin.word.withIndex()) {
            if (v != word.word[i]) ret++
            if (ret > 1) return 0
        }
        return ret
    }

    fun solution(begin: String, target: String, words: Array<String>): Int {
        var beginW: Word
        val que = ArrayDeque<Word>()
        val wordList = words.map { Word(it) }

        if (!words.contains(target)) return 0
        que.add(Word(begin))
        while (que.isNotEmpty()) {
            beginW = que.poll()
            for (e in wordList) {
                if (!e.visit && compareWord(beginW, e) == 1) {
                    e.visit = true
                    e.diffCnt = beginW.diffCnt + 1
                    if (e.word == target) return  e.diffCnt
                    que.add(e)
                }
            }
        }
        return 0
    }
}