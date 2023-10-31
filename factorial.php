<?php
/**
 * Calculate the factorial of a number using recursion.
 *
 * @param int $n The number for which to calculate the factorial.
 * @return int The factorial of the given number.
 */
function factorial($n) {
    if ($n <= 1) {
        return 1;
    } else {
        return $n * factorial($n - 1);
    }
}

// Example usage:
$number = 5;
$result = factorial($number);
echo "The factorial of $number is $result";
?>
