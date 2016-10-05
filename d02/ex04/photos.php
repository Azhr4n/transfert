#!/usr/bin/php

<?php

if ($argc > 1)
{
	$fd = curl_init($argv[1]);

	$page = curl_exec($fd);

	echo "$page\n";

	curl_close($fd);
}

?>
