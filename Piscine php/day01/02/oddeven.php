#!/usr/bin/php
<?php
echo 'Entrez un nombre: ';
if (!is_numeric($nbr = trim(fgets(STDIN))))
	echo '\''.$nbr. '\' n\'est pas un chiffre' ."\n";
else if ($nbr[-1] % 2 == 0)
	echo 'Le chiffre ' .$nbr. ' est pair!' ."\n";
else if ($nbr[-1] % 2 != 0)
	echo 'Le chiffre ' .$nbr. ' est impair!' ."\n";
?>
