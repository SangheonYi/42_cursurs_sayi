import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.StringBuilder
import java.util.ArrayDeque
import kotlin.math.absoluteValue

class GoStack
{
    var program = arrayListOf<String>()
    var input = arrayListOf<String>()
    var stack = ArrayDeque<Int>()
    var output = StringBuilder()

    fun runProgram()
    {
        var result: Int

        for (i in 1 .. input[0].toInt())
        {
            result = input[i].toInt()
            stack.push(result)
            for (j in 0 until program.size - 1)
            {
                result = calculate(program[j])
                if (result.absoluteValue >= 1000000000) break
            }
            stack.pop()
            if (result.absoluteValue < 1000000000 && stack.isEmpty()) output.append("$result\n")
            else output.append("ERROR\n")
            stack.clear()
        }
    }
    fun calculate(op:String): Int
    {
        val tmp = op.split(" ")
        val tmpInt: Int
        val tmpInt2: Int

        when (tmp[0])
        {
            //NUM X: X를 스택의 가장 위에 저장한다. (0 ≤ X ≤ 109)
            "NUM"-> stack.push(tmp[1].toInt())
            //POP: 스택 가장 위의 숫자를 제거한다.
            "POP"-> stack.pop()
            //INV: 첫 번째 수의 부호를 바꾼다. (42 -> -42)
            "INV"-> stack.push(-stack.pop())
            //DUP: 첫 번째 숫자를 하나 더 스택의 가장 위에 저장한다.
            "DUP"-> stack.push(stack.first)
            //SWP: 첫 번째 숫자와 두 번째 숫자의 위치를 서로 바꾼다.
            "SWP"->{
                tmpInt = stack.pop()
                tmpInt2 = stack.pop()
                stack.push(tmpInt)
                stack.push(tmpInt2)
            }
            //ADD: 첫 번째 숫자와 두 번째 숫자를 더한다.
            "ADD"-> stack.push(stack.pop() + stack.pop())
            //SUB: 첫 번째 숫자와 두 번째 숫자를 뺀다. (두 번째 - 첫 번째)
            "SUB"-> {
                tmpInt = stack.pop()
                tmpInt2 = stack.pop()
                stack.push(tmpInt2 - tmpInt)
            }
            //MUL: 첫 번째 숫자와 두 번째 숫자를 곱한다.
            "MUL"-> {
                tmpInt = stack.pop()
                tmpInt2 = stack.pop()
                stack.push(tmpInt2 * tmpInt)
            }
            //DIV: 첫 번째 숫자로 두 번째 숫자를 나눈 몫을 저장한다. 두 번째 숫자가 피제수, 첫 번째 숫자가 제수이다.
            "DIV"-> {
                tmpInt = stack.pop()
                tmpInt2 = stack.pop()
                stack.push(tmpInt2 / tmpInt)
            }
            //MOD: 첫 번째 숫자로 두 번째 숫자를 나눈 나머지를 저장한다. 두 번째 숫자가 피제수, 첫 번째 숫자가 제수이다.
            "MOD"-> {
                tmpInt = stack.pop()
                tmpInt2 = stack.pop()
                stack.push(tmpInt2 % tmpInt)
            }
            else -> return 0
        }
        return stack.first
    }
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val go = GoStack()
    var tmp = readLine()

    while (!tmp.equals("QUIT"))
    {
        go.program.clear()
        while (!tmp.equals("END"))
        {
            go.program.add(tmp)
            tmp = readLine()
        }
        go.program.add(tmp)
        tmp = readLine()
        go.input.clear()
        while (!tmp.equals(""))
        {
            go.input.add(tmp)
            tmp = readLine()
        }
        go.input.add(tmp)
        go.runProgram()
        go.output.append('\n')
        tmp = readLine()
    }
    println(go.output)
}