#!/usr/bin/php
<?php
function ft_split($string)
{
	return array_filter(array_reverse(explode(" ", trim($string))));
}
?>
