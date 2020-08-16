import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.StringBuilder
import java.util.ArrayDeque
import kotlin.math.absoluteValue

class GoStack {
    var program = arrayListOf<String>()
    var input = arrayListOf<String>()
    var stack = ArrayDeque<Int>()
    var output = StringBuilder()

    fun runProgram() {
        var result: Int
        var err = true
        for (i in 1..input[0].toInt()) {
            result = input[i].toInt()
            stack.push(result)
            for (j in 0 until program.size - 1) {
                result = calculate(program[j])
                if (result > 1000000000) break
            }
            if (result.absoluteValue <= 1000000000 && stack.size == 1) output.append("${stack.pop()}\n")
            else output.append("ERROR\n")
            stack.clear()
        }
    }

    fun calculate(op: String): Int {
        val tmp = op.split(" ")
        val tmpInt: Int
        val tmpInt2: Int

        when (tmp[0]) {
            "NUM" -> stack.push(tmp[1].toInt())
            "POP" -> {
                if (stack.isEmpty())
                    return Int.MAX_VALUE
                stack.pop()
            }
            "INV" -> {
                if (stack.isEmpty())
                    return Int.MAX_VALUE
                stack.push(-stack.pop())
            }
            "DUP" -> {
                if (stack.isEmpty())
                    return Int.MAX_VALUE
                stack.push(stack.first)
            }
            "SWP", "ADD", "SUB", "MUL", "DIV", "MOD" -> {
                if (stack.isEmpty())
                    return Int.MAX_VALUE
                tmpInt = stack.pop()
                if (stack.isEmpty())
                    return Int.MAX_VALUE
                tmpInt2 = stack.pop()
                when (tmp[0]) {
                    "SWP" -> {
                        stack.push(tmpInt)
                        stack.push(tmpInt2)
                    }
                    "ADD" -> stack.push(tmpInt + tmpInt2)
                    "SUB" -> stack.push(tmpInt2 - tmpInt)
                    "MUL" -> {
                        if (tmpInt.toBigInteger().multiply(tmpInt2.toBigInteger()).abs() > 1000000000.toBigInteger())
                            return Int.MAX_VALUE
                        stack.push(tmpInt2 * tmpInt)
                    }
                    "DIV", "MOD" -> {
                        if (tmpInt == 0)
                            return Int.MAX_VALUE
                        if (tmp[0].equals("DIV"))
                            stack.push(tmpInt2 / tmpInt)
                        else
                            stack.push(tmpInt2 % tmpInt)
                    }
                    else -> return Int.MAX_VALUE
                }
            }
        }
        if (stack.isEmpty())
            return 0
        return stack.first
    }
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val go = GoStack()
    var tmp = readLine()

    while (!tmp.equals("QUIT")) {
        go.program.clear()
        while (!tmp.equals("END")) {
            go.program.add(tmp)
            tmp = readLine()
        }
        go.program.add(tmp)
        tmp = readLine()
        go.input.clear()
        while (!tmp.equals("")) {
            go.input.add(tmp)
            tmp = readLine()
        }
        go.input.add(tmp)
        go.runProgram()
        go.output.append('\n')
        tmp = readLine()
    }
    go.output.deleteCharAt(go.output.lastIndex)
    println(go.output)
}
