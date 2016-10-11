<?php

class Color {

	public static $verbose = false;
	public $red;
	public $green;
	public $blue;

	function __construct(array $kwargs) {
		if (array_key_exists('rgb', $kwargs)) {
			$value = intval($kwargs['rgb']);
			$this->red = ($value >> 16) & 0xFF;
			$this->green = ($value >> 8) & 0xFF;
			$this->blue = ($value) & 0xFF;
		}
		else if (array_key_exists('red', $kwargs) && array_key_exists('green', $kwargs) && array_key_exists('blue', $kwargs)) {
			$this->red = intval($kwargs['red']);
			$this->green = intval($kwargs['green']);
			$this->blue = intval($kwargs['blue']);
		}
		if (self::$verbose)
			print('Color( red: '.sprintf("%3s",$this->red).', green: '.sprintf("%3s",$this->green).', blue: '.sprintf("%3s",$this->blue).' ) constructed.'."\n");
	}

	function __destruct() {
		if (self::$verbose)
			print('Color( red: '.sprintf("%3s",$this->red).', green: '.sprintf("%3s",$this->green).', blue: '.sprintf("%3s",$this->blue).' ) destructed.'."\n");
	}

	public function add(Color $color) {
		return new Color(array('red'=>$this->red + $color->red, 'green'=>$this->green + $color->green, 'blue'=>$this->blue + $color->blue));
	}

	public function sub(Color $color) {
		return new Color(array('red'=>$this->red - $color->red, 'green'=>$this->green - $color->green, 'blue'=>$this->blue - $color->blue));
	}

	public function mult($factor) {
		return new Color(array('red'=>$this->red * $factor, 'green'=>$this->green * $factor, 'blue'=>$this->blue * $factor));
	}

	public function __toString() {
		return 'Color( red: '.sprintf("%3s",$this->red).', green: '.sprintf("%3s",$this->green).', blue: '.sprintf("%3s",$this->blue).' )';
	}

	public static function doc() {
		return file_get_contents('Color.doc.txt')."\n";
	}

}

?>