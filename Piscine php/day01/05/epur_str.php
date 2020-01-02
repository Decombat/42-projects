#!/usr/bin/php
<?php
if ($argc != 2)
  return 0;
$str = preg_split('/ +/', trim($argv[1]));
for ($i=0; $str[$i] ; $i++)
{
  echo $str[$i];
  if ($str[$i + 1])
    echo ' ';
  else
    echo "\n";
}
?>
