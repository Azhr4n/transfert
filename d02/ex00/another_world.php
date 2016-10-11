#!/usr/bin/php
<?php
if ($argc > 1)
	echo preg_replace('/[ \t]{2,}/', ' ', trim($argv[1]));
echo "\n";
?>
