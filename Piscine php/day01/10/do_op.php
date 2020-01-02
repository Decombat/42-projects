#!/usr/bin/php
<?php
if ($argc != 4)
	return ;
$ope = trim($argv[2]);
$argv[1] = intval($argv[1]);
$argv[3] = intval($argv[3]);
if ($ope === '%' || $ope === '/')
	if ($argv[3] === 0)
		return ;
if ($ope === '+')
	$var = $argv[1] + $argv[3];
else if ($ope === '-')
	$var = $argv[1] - $argv[3];
else if ($ope === '*')
	$var = $argv[1] * $argv[3];
else if ($ope === '/')
	$var = $argv[1] / $argv[3];
else if ($ope === '%')
	$var = $argv[1] % $argv[3];
echo $var."\n";
?>
