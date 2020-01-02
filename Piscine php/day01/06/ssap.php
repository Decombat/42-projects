#!/usr/bin/php
<?php
if ($argc < 2)
	return 0;
$c = 0;
for ($i = 1; $i < $argc ; $i++)
{
		$x = 0;
		$str = array_filter(preg_split('/\s+/', trim($argv[$i])));
		while ($str[$x])
			$array[$c++] = $str[$x++];
}
array_multisort($array, SORT_ASC, SORT_STRING);
for ($i = 0; $array[$i] ; $i++)
	echo $array[$i]."\n";
?>
