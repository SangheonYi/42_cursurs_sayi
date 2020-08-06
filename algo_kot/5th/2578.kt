class BingoBoard()
{
	var board = List<List<Int>>(5, {readLine()!!.split(' ').map { it.toInt() }})
	var row = IntArray(5)
	var col = IntArray(5)
	var dia = 0
	var revdia = 0
	var cnt = 0

	fun isBingo(rowIdx:Int, colIdx:Int)
	{
		if (row[rowIdx] == 5)
		{
			row[rowIdx] = 0
			cnt++
			pt(rowIdx, colIdx, 1)

		}
		else if (col[colIdx] == 5)
		{
			col[colIdx] = 0
			cnt++
			pt(rowIdx, colIdx, 2)
		}
		else if (dia == 5)
		{
			dia = 0
			cnt++
			pt(rowIdx, colIdx, 3)
		}
		else if (revdia == 5)
		{
			revdia = 0
			cnt++
			pt(rowIdx, colIdx, 4)
		}
	}

	fun whichRow(i:Int):Int
	{
		var idx = 0

		while (idx < 5 && !board[idx].contains(i))
			idx++
		return idx
	}

	fun pt(r:Int, c:Int, num:Int)
	{
		println("===============row${r} col${c} ${board[r][c]} Bingo $num line")
	}
}

fun main(args: Array<String>) {
	var rowIdx:Int
	var colIdx:Int
	var bingo = BingoBoard()
	var mc = List<List<Int>>(5, {readLine()!!.split(' ').map { it.toInt() }})
	var i = -1
	var j:Int

	println("=======")
	println(bingo.board)
	println("=======")
	println(mc)
	println("=======")
	while (++i < 5)
	{
		j = -1
		while (++j < 5)
		{
			rowIdx = bingo.whichRow(mc[i][j])
			colIdx = bingo.board[rowIdx].indexOf(mc[i][j])
			bingo.row[rowIdx]++
			bingo.col[colIdx]++
			if (rowIdx == colIdx) bingo.dia++
			if (rowIdx + colIdx == 4) bingo.revdia++
			bingo.isBingo(rowIdx, colIdx)
			// println("i:$i, j:$j")
			// println("rowIdx:$rowIdx, colIdx:$colIdx")
			// println("bingboard:${bingo.board[rowIdx][colIdx]} dia: ${bingo.dia}")
			if (bingo.cnt == 3)
			{
				println(i * 5 + j + 1)
				return
			}
		}
	}
}
