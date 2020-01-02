#!/usr/bin/php
<?php
  if ($argc < 2)
  return ;
  echo preg_replace_callback( '/(?<=<a)(.*?)(?=\/a>)/is', ft_split, file_get_contents($argv[1]));
  function ft_split($param) {
    $param[0] = preg_replace_callback( '/(?<=title=\")(.*?)\"/is', ft_capit, $param[0]);
    $param[0] = preg_replace_callback( '/(?<=>)(.*?)(?=<)/is', ft_capit, $param[0]);
    return $param[0];
  }
  function ft_capit($param) { return strtoupper($param[0]);
  }
?>
