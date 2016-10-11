<?php
require_once('Vertex.class.php');

class Vector {

	public static $verbose = false;

	private $_x;
	private $_y;
	private $_z;
	private	$_w;

	function __construct(array $kwargs) {
		if (array_key_exists('orig', $kwargs) && is_a($kwargs['orig'], Vertex))
			$origine = $kwargs['orig'];
		else
			$origine = new Vertex(array('x'=>0, 'y'=>0, 'z'=>0));
		if (array_key_exists('dest', $kwargs) && is_a($kwargs['dest'], Vertex))
		{
			$this->_x = $kwargs['dest']->getX() - $origine->getX();
			$this->_y = $kwargs['dest']->getY() - $origine->getY();
			$this->_z = $kwargs['dest']->getZ() - $origine->getZ();
			$this->_w = $kwargs['dest']->getW() - $origine->getW();
		}
		if (self::$verbose)
			print('Vector( x:'.sprintf("%.2f", $this->_x).', y:'.sprintf("%.2f", $this->_y).', z:'.sprintf("%.2f", $this->_z).', w:'.sprintf("%.2f", $this->_w).' ) constructed'."\n");
	}

	function __destruct() {
		if (self::$verbose)
			print('Vector( x:'.sprintf("%.2f", $this->_x).', y:'.sprintf("%.2f", $this->_y).', z:'.sprintf("%.2f", $this->_z).', w:'.sprintf("%.2f", $this->_w).' ) destructed'."\n");
	}

	function getX() { return $this->_x; }
	function getY() { return $this->_y; }
	function getZ() { return $this->_z; }
	function getW() { return $this->_w; }

	function magnitude() {
		return floatval(sqrt(pow($this->_x, 2) + pow($this->_y, 2) + pow($this->_z, 2)));
	}

	function normalize() {
		$norme = $this->magnitude();
		return new Vector(array('dest'=>new Vertex(array('x'=>$this->_x / $norme, 'y'=>$this->_y / $norme, 'z'=>$this->_z / $norme))));
	}

	function add(Vector $rhs) {
		$x = $this->getX() + $rhs->getX();
		$y = $this->getY() + $rhs->getY();
		$z = $this->getZ() + $rhs->getZ();
		return new Vector(array('dest'=>new Vertex(array('x'=>$x, 'y'=>$y, 'z'=>$z))));
	}

	function sub(Vector $rhs) {
		$x = $this->getX() - $rhs->getX();
		$y = $this->getY() - $rhs->getY();
		$z = $this->getZ() - $rhs->getZ();
		return new Vector(array('dest'=>new Vertex(array('x'=>$x, 'y'=>$y, 'z'=>$z))));
	}

	function opposite()	{
		return new Vector(array('dest'=>new Vertex(array('x'=>$this->_x * -1, 'y'=>$this->_y * -1, 'z'=>$this->_z * -1))));
	}

	function scalarProduct($k) {
		return new Vector(array('dest'=>new Vertex(array('x'=>$this->_x * $k, 'y'=>$this->_y * $k, 'z'=>$this->_z * $k))));
	}

	function dotProduct(Vector $rhs) {
		return 	floatval($this->_x * $rhs->getX() + $this->_y * $rhs->getY() + $this->_z * $rhs->getZ());
	}

	function crossProduct(Vector $rhs) {
		return new Vector(array('dest'=>new Vertex(
			array('x'=>$this->_y * $rhs->getZ() - $this->_z * $rhs->getY(),
				'y'=>$this->_z * $rhs->getX() - $this->_x * $rhs->getZ(),
				'z'=>$this->_x * $rhs->getY() - $this->_y * $rhs->getX()))));
	}

	function cos(Vector $rhs) {
		return floatval($this->dotProduct($rhs) / ($this->magnitude() * $rhs->magnitude()));
	}

	function __toString() {
		return 'Vector( x:'.sprintf("%.2f", $this->_x).', y:'.sprintf("%.2f", $this->_y).', z:'.sprintf("%.2f", $this->_z).', w:'.sprintf("%.2f", $this->_w).' )';
	}

	static function doc() {
		return file_get_contents('Vector.doc.txt')."\n";
	}

}

?>