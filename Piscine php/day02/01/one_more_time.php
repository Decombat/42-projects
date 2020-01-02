#!/usr/bin/php
<?php
if ($argc != 2)
	return ;
date_default_timezone_set("Europe/Paris");
$tab = preg_split("# |:#", $argv[1]);
if (sizeof($tab) !== 7)
	return erreur();
if(!is_numeric($hour = $tab[4]) || $hour < 0 || $hour > 23)
	return erreur();
if(!is_numeric($min = $tab[5]) || $min < 0 || $min > 60)
	return erreur();
if(!is_numeric($sec = $tab[6]) || $sec < 0 || $sec > 60)
	return erreur();
if(!is_numeric($month = mois(strtolower($tab[2]))) || $month < 0 || $month > 12)
	return erreur();
if(!is_numeric($date = $tab[1]) || $date < 0 || $date > 31)
	return erreur();
if(!is_numeric($year = $tab[3]) || $year < 1970)
	return erreur();
echo mktime($hour,$min,$sec,$month,$date,$year)."\n";
function erreur()
{
	echo "Wrong Format\n";
}
function mois($month)
{
	if ($month === "janvier" || $month === "january")
		$month = 01;
	else if ($month === "fevrier" || $month === "february")
		$month = 02;
	else if ($month === "mars" || $month === "march")
		$month = 03;
	else if ($month === "avril" || $month === "april")
		$month = 04;
	else if ($month === "mai" || $month === "may")
		$month = 05;
	else if ($month === "juin" || $month === "june")
		$month = 06;
	else if ($month === "juilllet" || $month === "july")
		$month = 07;
	else if ($month === "aout" || $month === "august")
		$month = 08;
	else if ($month === "septembre" || $month === "september")
		$month = 09;
	else if ($month === "octobrer" || $month === "october")
		$month = 10;
	else if ($month === "novembre" || $month === "november")
		$month = 11;
	else if ($month === "decembre" || $month === "december")
		$month = 12;
	return $month;
}
?>
