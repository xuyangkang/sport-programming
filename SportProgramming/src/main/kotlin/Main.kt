
import java.io.PrintWriter
import java.util.*

fun PrintWriter.solve() {
// solution goes here
}

fun main() {
    _writer.solve(); _writer.flush()
}

/** IO code start */
//original source: https://codeforces.com/blog/entry/71089
//@JvmField val INPUT = File("input.txt").inputStream()
//@JvmField val OUTPUT = File("output.txt").outputStream()
@JvmField
val INPUT = System.`in`

@JvmField
val OUTPUT = System.out

@JvmField
val _reader = INPUT.bufferedReader()
fun readLine(): String? = _reader.readLine()
fun readLn() = _reader.readLine()!!

@JvmField
var _tokenizer: StringTokenizer = StringTokenizer("")
fun read(): String {
    while (_tokenizer.hasMoreTokens().not()) _tokenizer = StringTokenizer(_reader.readLine() ?: return "", " ")
    return _tokenizer.nextToken()
}

fun readInt() = read().toInt()
fun readDouble() = read().toDouble()
fun readLong() = read().toLong()
fun readStrings(n: Int) = Array(n) { read() }
fun readLines(n: Int) = Array(n) { readLn() }
fun readIntArray(n: Int) = IntArray(n) { read().toInt() }
fun readDoubleArray(n: Int) = DoubleArray(n) { read().toDouble() }
fun readLongArray(n: Int) = LongArray(n) { read().toLong() }

@JvmField
val _writer = PrintWriter(OUTPUT, false)

fun bigMod(B: Long, P: Long, M: Long): Long {
    var (r, p, b) = listOf(1, P, B)
    while (p > 0) {
        if (p % 2L == 1L) r = (r * b) % M
        p /= 2
        b = (b * b) % M
    }
    return r
}