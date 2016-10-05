#!/usr/bin/php
<?php
if ($argc > 1)
{
	$str = file_get_contents($argv[1]);
	preg_match_all('/<a.*?<\/a>/', $str, $ret);
	$upped_ret = $ret;
	$i = 0;
	$length = count($ret[0]);
	while ($i < $length)
	{
		preg_match('/title {0,}= {0,}"(.*)"/', $ret[0][$i], $titles[$i]);
		$upped_title = preg_replace('/'.$titles[$i][1].'/', strtoupper($titles[$i][1]), $titles[$i][0]);
		$upped_ret[0][$i] = preg_replace('/'.$titles[$i][0].'/', $upped_title, $upped_ret[0][$i]);
		preg_match_all('/>(.*?)</', $ret[0][$i], $che[$i]);
		$j = 0;
		$length_che = count($che[$i]);
		while ($j < $length_che)
		{
			$upped_che = preg_replace('/'.$che[$i][1][$j].'/', strtoupper($che[$i][1][$j]), $che[$i][0][$j]);
			$upped_ret[0][$i] = preg_replace('/'.$che[$i][0][$j].'/', $upped_che, $upped_ret[0][$i]);
			$j++;
		}
		$i++;
	}
	$new_str = $str;
	$length = count($upped_ret[0]);
	for ($i = 0; $i < $length; $i++)
	{
		$fusion = explode($ret[0][$i], $new_str);
		$new_str = implode($upped_ret[0][$i], $fusion);
	}
	print($new_str);
}
?>