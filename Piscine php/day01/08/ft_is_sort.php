#!/usr/bin/php
<?php
	function ft_is_sort($array)
	{
		$array_sort = $array;
		array_multisort($array_sort, SORT_ASC, SORT_STRING);
		for ($i=0; $array[$i] ; $i++)
			if ($array[$i] !== $array_sort[$i])
				return 0;
		return 1;
	}
?>
