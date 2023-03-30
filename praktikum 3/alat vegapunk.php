<?php
// Input: two large numbers a and b
$a = readline();
$b = readline();

// Multiply a and b using bcmul function
$result = bcmul($a,$b);

// Print the result
echo $result;
?>