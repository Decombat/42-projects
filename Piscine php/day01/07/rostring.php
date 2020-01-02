#!/usr/bin/php
<?php
if ($argc != 2)
  return 0;
$str = array_filter(preg_split('/\s+/', trim($argv[1])));
$str_copie = $str;
$str[0] = $str_copie[sizeof($str_copie) - 1];
$str[sizeof($str) - 1] = $str_copie[0];
for ($i=0; $str[$i] ; $i++)
{
  echo $str[$i];
  if ($str[$i + 1])
    echo ' ';
}
?>
