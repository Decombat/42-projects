#!/usr/bin/php
<?php
if ($argc != 2) {
  echo "Incorrect Parameters\n";
  return ;}
$calc = preg_replace('/\s+/','', trim($argv[1]));
if (!preg_match("#\d[+-/*%]\d#",$calc)) {
  echo "Syntax Error\n";
  return ;}
preg_match_all("#\d*|.#", $calc, $tab, PREG_PATTERN_ORDER);
$val1 = intval($tab[0][0]);
$val3 = intval($tab[0][3]);
$ope = $tab[0][2];
if ($ope === '%' || $ope === '/')
	if ($val3 === 0)
		return ;
if ($ope === '+')
	$var = $val1 + $val3;
else if ($ope === '-')
	$var = $val1 - $val3;
else if ($ope === '*')
	$var = $val1 * $val3;
else if ($ope === '/')
	$var = $val1 / $val3;
else if ($ope === '%')
	$var = $val1 % $val3;
echo $var."\n";
?>
