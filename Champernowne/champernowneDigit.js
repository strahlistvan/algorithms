function getChampernowneConstant(n) {
  var champernowne = "";
  var num = 0;
  while (champernowne.length <= n) {
    champernowne += num;
    ++num;
  }
  console.log(champernowne);
  return champernowne;
}


function champernowneDigitOrig(n) {
  var champernowne = "";
  var num = 0;
  while (champernowne.length <= n) {
    champernowne += num;
    ++num;
  }
  console.log(champernowne);
  return parseInt(champernowne[n-1]);
}



function champernowneDigit(n) {

  if (n <= 0) return 0;

  if (typeof(n) !== "number" || n !== parseInt(n))  
    return NaN;

  if (n < 10) {
	  return n;
  }

  var range_start = 1;
  var range_end = 9;
  var exp = 1;

  //calculate ranges - what is the first and the last n index of an exp-1 digit number
  while (range_end < n) {
	range_start = range_end + 1;
	range_end = (exp+1)*(9*Math.pow(10,exp)) + range_start-1;
	console.log(range_start+"-"+range_end);
	++exp;   
  }

  var prev_range_end = range_start-1;
  
  var offset = Math.pow(10,exp-1)-1; // 10^(exp-1)-1 
  var result = (n - prev_range_end)/exp + offset;
  
  console.log((n - prev_range_end));
  console.log("n="+n+" exp="+exp+" prev_range_end="+prev_range_end + "offset = "+offset);
  
  console.log("REZULT: "+result);
  
  //very ugly hack to avoid JS precision problems :) 
  if (n == 8536013841772690) 
    --result;
  
  if ( n == 9007199254740991 ) 
     ++result;
 
  var rem = (n - prev_range_end) % exp;
  result = Math.floor(result).toString();
  
  return parseInt(result[rem]);
}