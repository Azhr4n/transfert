#!/usr/bin/php
<?php

function getImage($url)
{
	$fd = curl_init($url);
	curl_setopt($fd, CURLOPT_HEADER, 0);
	curl_setopt($fd, CURLOPT_RETURNTRANSFER, 1);
	curl_setopt($fd, CURLOPT_BINARYTRANSFER,1);
	curl_setopt($fd, CURLOPT_USERAGENT, 'Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.8.1.13) Gecko/20080311 Firefox/2.0.0.13');
	$data = curl_exec($fd);
	return $data;
}

function getImageURL($value)
{
	preg_match('~src {0,}= {0,}"(.*?)"~', $value, $ret);
	if (!strncmp($ret[1], 'http://', 7) || !strncmp($ret[1], 'https://', 8))
	{
		$explosion = explode('?', $ret[1]);
		if (count($explosion) < 2)
			return $ret[1];
	}
	return NULL;
}

function getImageName($image)
{
	$explosion = explode('/', $image);
	$count = count($explosion);
	return ($explosion[$count - 1]);
}

function getSiteName($url)
{
	if (!strncmp($url, 'http://', 7))
	{
		$name = substr($url, 7);
		if (strncmp($name, 'www', 3))
			$name = "www".$name;
		return $name;
	}
	else if (!strncmp($url, 'https://', 8))
	{
		$name = substr($url, 8);
		if (strncmp($name, 'www', 3))
			$name = "www".$name;
		return $name;
	}
	else
		return NULL;
}

function addrValid($url)
{
	$ch = curl_init($url);
	curl_setopt($ch, CURLOPT_NOBODY, true);
	curl_exec($ch);
	$retcode = curl_getinfo($ch, CURLINFO_HTTP_CODE);
	curl_close($ch);
	if ($retcode == 200)
		return true;
	return false;
}

if ($argc > 1)
{
	if (addrValid($argv[1]))
	{
		$data = file_get_contents($argv[1]);
		if ($data != FALSE)
		{
			if (($site_name = getSiteName($argv[1])) != NULL)
			{
				if (!file_exists($site_name))
					mkdir($site_name);
				preg_match_all('~<img .*?>|<IMG .*?>~', $data, $ret);
				foreach ($ret[0] as $value) {
					if (($image_url = getImageURL($value)) != NULL)
					{
						$name = getImageName($image_url);
						$file = fopen($site_name.'/'.$name, 'a+');
						$image = getImage($image_url);
						fwrite($file, $image);
						fclose($file);
						exit(1);
					}
				}
			}
		}
	}
	else
		echo "Address invalid.\n";
}

?>