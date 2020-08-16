import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.StringBuilder
import java.math.BigInteger
import java.util.ArrayDeque
class Gostack
{
    var program = arrayListOf<String>()
    var input = arrayListOf<String>()
    var stack = ArrayDeque<Int>()
    var output = StringBuilder()

    fun runProgram()
    {
        var firstIn: Int
        var result = ""

        for (i in 1 .. input[0].toInt())
        {
            firstIn = input[i].toInt()
            stack.push(firstIn)
            for (j in 0 until program.size)
            {
                result = calculate(program[j])
                if (result.equals("ERROR"))
                    break
            }
            output.append("$result\n")
        }
    }
    fun calculate(op:String): String
    {
        var tmp = op.split(" ")
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
            "SWP"
            //ADD: 첫 번째 숫자와 두 번째 숫자를 더한다.
            //SUB: 첫 번째 숫자와 두 번째 숫자를 뺀다. (두 번째 - 첫 번째)
            //MUL: 첫 번째 숫자와 두 번째 숫자를 곱한다.
            //DIV: 첫 번째 숫자로 두 번째 숫자를 나눈 몫을 저장한다. 두 번째 숫자가 피제수, 첫 번째 숫자가 제수이다.
            //MOD: 첫 번째 숫자로 두 번째 숫자를 나눈 나머지를 저장한다. 두 번째 숫자가 피제수, 첫 번째 숫자가 제수이다.
        }
        return "ERROR"
    }
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val go = Gostack()
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
        tmp = readLine()
    }
    println(go.output)
}