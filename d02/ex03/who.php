#!/usr/bin/php
<?php

date_default_timezone_set('Europe/paris');
$usr = get_current_user();
$file = file_get_contents("/var/run/utmpx");
$sub = substr($file, 1256);
$result = array();
$typedef  = 'a256user/a4id/a32line/ipid/itype/I2time/a256host/i16pad';
while ($sub != NULL) {
	$array = unpack($typedef, $sub);
	if (strcmp(trim($array[user]), $usr) == 0 && $array[type] == 7)
	{
		$trimmed_usr = trim($array[user]);
		$trimmed_usr = $trimmed_usr . "  ";
		$line = trim($array[line]);
		$line = $line . "  ";
		$date = date("M  j H:i", $array["time1"]);
		$tab = array($trimmed_usr.$line.$date);
		$result = array_merge($result, $tab);
	}
	$sub = substr($sub, 628);
}
sort($result);
foreach ($result as $value) {
	echo $value;
	echo "\n";
}

?>