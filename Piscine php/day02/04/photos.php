#!/usr/bin/php
<?php
if ($argc !== 2 || ft_url_exist($argv[1]) === false)
  return ;
$file = ft_after('https://', $argv[1]);
$url = file_get_contents($argv[1]);
preg_match_all( "/(?<=<img src=\")(https:.*?)(?=\")/si", $url, $match, PREG_SET_ORDER); // gerer plusieurs espaces entre img et src ?? [\s+?]
@mkdir($file, 0755);
foreach  ($match as $val)
  ft_getimg ($val[0], $file);

function ft_getimg($val, $file){
  $name = file_get_contents($val);
  file_put_contents($file.basename($val), $name);
}
function ft_url_exist($url){
  if (@fopen($url, 'r'))
    return true;
  else
    return false;
}
function ft_after($this, $inthat){
     if (strpos($inthat, $this) === false)
      return ;
     return substr($inthat, strpos($inthat,$this)+strlen($this));
 }
?>
