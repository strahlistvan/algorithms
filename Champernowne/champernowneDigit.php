<?php

function champernowneDigit($n) {
  $exp = 0;
  $range_start = 1;
  $range_end = 0;

  if ($n < 0) return 0;

 // if (!is_numeric($n) || n !== (int)n)  
 //   return NaN;

  if ($n <= 10) {
	  return $n-1;
  }
  
  //calculate ranges - what is the first and the last n index of an exp-1 digit number
  while ($range_end < $n) {
	$range_start = $range_end + 1;
	$range_end = ($exp+1)*(9*pow(10,$exp)) + $range_start-1;	   
	++$exp;   
  }

  $offset = pow(10,$exp-1); // 10^(exp-1) 
  $result = ($n - $range_start-1)/$exp + $offset;

  //very ugly hack to avoid JS precision problems :) 
  //if (n == 8536013841772690) 
  //  --result;
  
 // if ( n == 9007199254740991 ) 
 //    ++result;
 
  $rem = ($n - $range_start-1) % $exp;
  $result = (string) floor($result);
  
  echo $result[$rem]."\n";
  return (int) $result[$rem];
}



champernowneDigit(0);
champernowneDigit(1);
champernowneDigit(20);
champernowneDigit(100);
champernowneDigit(1000);
champernowneDigit(10000);
champernowneDigit(100000);
champernowneDigit(999999);



?>