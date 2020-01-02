#!/usr/bin/php
<?php
if (argc < 2)
  return 0;
for ($i = 1; $i < $argc ; $i++)
  echo($argv[$i]."\n");
?>
