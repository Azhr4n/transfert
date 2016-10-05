#!/usr/bin/php

<?php
date_default_timezone_set('Europe/Paris');

function checkFormat($regexp, $str)
{
	if (preg_match('/('.$regexp[0].') ('.$regexp[1].') ('.$regexp[2].') ('.$regexp[3].') ('.$regexp[4].$regexp[5].$regexp[6].')$/', $str))
		return True;
	return False;
}

function convertMonth($str)
{
	$regexp = array("[J|j]anvier", "[F|f][é|e]vrier", "[M|m]ars", "[A|a]vril", "[M|m]ai",
		"[J|j]uin", "[J|j]uillet", "[A|a]o[û|u]t", "[S|s]eptembre", "[O|o]ctobre", "[N|n]ovembre", "[D|d][é|e]cembre");
	$inc = 1;
	foreach ($regexp as $month)
	{
		if (preg_match('/^'.$month.'$/', $str))
			return ($inc);
		$inc++;
	}
}

if ($argc > 1)
{
	$regexp = array("^[L|l]undi|^[M|m]ardi|^[M|m]ercredi|^[J|j]eudi|^[V|v]endredi|^[S|s]amedi|^[D|d]imanche",
		"[0-9]{1,2}",
		"[J|j]anvier|[F|f][é|e]vrier|[M|m]ars|[A|a]vril|[M|m]ai|[J|j]uin|[J|j]uillet|[A|a]o[û|u]t|[S|s]eptembre|[O|o]ctobre|[N|n]ovembre|[D|d][é|e]cembre",
		"[0-9]{4}",
		"(([0-1]{1}[0-9]{1})|([2]{1}[0-3]{1})):",
		"[0-5]{1}[0-9]{1}:",
		"[0-5]{1}[0-9]{1}$");

	if (checkFormat($regexp, $argv[1]) == FALSE)
		echo "Wrong format.";
	else
	{
		preg_match('/'.$regexp[0].'/', $argv[1], $day);
		preg_match('/'.$regexp[1].'/', $argv[1], $num_day);
		preg_match('/'.$regexp[2].'/', $argv[1], $month);
		$month = convertMonth($month[0]);
		preg_match('/'.$regexp[3].'/', $argv[1], $year);
		preg_match('/'.$regexp[4].'/', $argv[1], $hour);
		$hour = substr($hour[0], 0, 2);
		preg_match('/:'.$regexp[5].'/', $argv[1], $min);
		$min = substr($min[0], 1, 2);
		preg_match('/'.$regexp[6].'/', $argv[1], $sec);
		echo mktime($hour, $min, $sec[0], $month, $num_day[0], $year[0]);
	}

}
echo "\n";
?>
