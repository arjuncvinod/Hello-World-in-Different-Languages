object HelloWorldWithCalculation {
  def main(args: Array[String]): Unit = {
    println("Hello, World!")

    val num1 = 10
    val num2 = 5
    val sum = num1 + num2
    val product = num1 * num2

    println(s"Sum of $num1 and $num2 is: $sum")
    println(s"Product of $num1 and $num2 is: $product")
  }
}
