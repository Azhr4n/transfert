<?php
require_once('Color.class.php');

class Vertex {

	public static	$verbose = false;

	private	$_x;
	private	$_y;
	private	$_z;
	private	$_w;
	private	$_color;

	function __construct(array $kwargs) {
		if (array_key_exists('x', $kwargs) && array_key_exists('y', $kwargs) && array_key_exists('z', $kwargs)) {
			$this->_x = floatval($kwargs['x']);
			$this->_y = floatval($kwargs['y']);
			$this->_z = floatval($kwargs['z']);
		}
		if (array_key_exists('w', $kwargs))
			$this->_w = $kwargs['w'];
		else
			$this->_w = 1.0;
		if (array_key_exists('color', $kwargs))
			$this->_color = $kwargs['color'];
		else
			$this->_color = new Color(array('rgb'=>0xFFFFFF));
		if (self::$verbose)
			print('Vertex( x: '.sprintf("%.2f", $this->_x).', y: '.sprintf("%.2f", $this->_y).', z:'.sprintf("%.2f", $this->_z).', w:'.sprintf("%.2f", $this->_w).', '.$this->_color.' ) constructed'."\n");
	}

	function __destruct() {
		if (self::$verbose)
			print('Vertex( x: '.sprintf("%.2f", $this->_x).', y: '.sprintf("%.2f", $this->_y).', z:'.sprintf("%.2f", $this->_z).', w:'.sprintf("%.2f", $this->_w).', '.$this->_color.' ) destructed'."\n");
	}

	function getX() { return $this->_x;}
	function getY() { return $this->_y;}
	function getZ() { return $this->_z;}
	function getW() { return $this->_w;}
	function getColor() { return $this->_color;}

	function setX($val) { $this->_x = floatval($val); }
	function setY($val) { $this->_y = floatval($val); }
	function setZ($val) { $this->_z = floatval($val); }
	function setW($val) { $this->_w = floatval($val); }
	function setColor(Color $new_color) { $this->_color = $new_color; }

	function __toString() {
		if (self::$verbose)
			return 'Vertex( x: '.sprintf("%.2f", $this->_x).', y: '.sprintf("%.2f", $this->_y).', z:'.sprintf("%.2f", $this->_z).', w:'.sprintf("%.2f", $this->_w).', '.$this->_color.' )';
		return 'Vertex( x: '.sprintf("%.2f", $this->_x).', y: '.sprintf("%.2f", $this->_y).', z:'.sprintf("%.2f", $this->_z).', w:'.sprintf("%.2f", $this->_w).' )';
	}

	static function doc() {
		return file_get_contents('Vertex.doc.txt')."\n";
	}

}

?>