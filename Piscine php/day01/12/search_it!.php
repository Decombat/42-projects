#!/usr/bin/php
<?php
if ($argc < 3)
  return ;
$size = strlen($argv[1]);
for ($u = $argc; $u > 2 ; $u--)
  if (!strncmp($argv[1], $argv[$u], $size) && $argv[$u][$size] === ':')
    break;
if (strncmp($argv[1], $argv[$u], sizeof($argv[1])))
  return ;
preg_match("#:(.*)#", $argv[$u], $tab);
if ($tab[1])
  echo $tab[1]."\n";
?>
