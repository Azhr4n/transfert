<?php
require_once('Vertex.class.php');
require_once('Vector.class.php');

class Matrix {

	public static $verbose = false;

	const IDENTITY = 0;
	const SCALE = 1;
	const RX = 2;
	const RY = 3;
	const RZ = 4;
	const TRANSLATION = 5;
	const PROJECTION = 6;

	private $_type;

	private $_vtcX;
	private $_vtcY;
	private $_vtcZ;
	private $_vtcO;

	function __construct(array $kwargs) {
		if (array_key_exists('preset', $kwargs))
		{
			if ($kwargs['preset'] == self::IDENTITY) {
				$this->_type = self::IDENTITY;
				$this->_createIdentityMatrix();
				if (self::$verbose)
					print('Matrix IDENTITY instance constructed'.PHP_EOL);
			}
			else if ($kwargs['preset'] == self::TRANSLATION && is_a($kwargs['vtc'], Vector))
			{
				$this->_type = self::TRANSLATION;
				$this->_createTranslationMatrix($kwargs['vtc']);
				if (self::$verbose)
					print('Matrix TRANSLATION preset instance constructed'.PHP_EOL);
			}
		}
	}

	function __destruct() {

	}

	private function _createIdentityMatrix() {
		$this->_vtcX = new Vector(array('dest'=>new Vertex(array('x'=>1, 'y'=>0, 'z'=>0))));
		$this->_vtcY = new Vector(array('dest'=>new Vertex(array('x'=>0, 'y'=>1, 'z'=>0))));
		$this->_vtcZ = new Vector(array('dest'=>new Vertex(array('x'=>0, 'y'=>0, 'z'=>1))));
		$this->_vtcO = new Vector(array('dest'=>new Vertex(array('x'=>0, 'y'=>0, 'z'=>0, 'w'=>2))));
	}

	private function _createTranslationMatrix(Vector $vec) {
		$this->_createIdentityMatrix();
		$this->_vtcO = new Vector(array('dest'=>new Vertex(array('x'=>$vec->getX(), 'y'=>$vec->getY(), 'z'=>$vec->getZ(), 'w'=>2))));
	}

	function mult(Matrix $rhs) {
		return new Matrix(array());
	}

	function transformVertex(Vertex $vtx) {
		return new Vertex(array('x'=>0, 'y'=>0, 'z'=>0));
	}

	function __toString() {
		$first_line = "M | vtcX | vtcY | vtcZ | vtcO\n";
		$second_line = "-----------------------------\n";
		$third_line = "x | ".sprintf("%.2f", $this->_vtcX->getX())." | ".sprintf("%.2f", $this->_vtcY->getX())." | ".sprintf("%.2f", $this->_vtcZ->getX())." | ".sprintf("%.2f", $this->_vtcO->getX())."\n";
		$fourth_line = "y | ".sprintf("%.2f", $this->_vtcX->getY())." | ".sprintf("%.2f", $this->_vtcY->getY())." | ".sprintf("%.2f", $this->_vtcZ->getY())." | ".sprintf("%.2f", $this->_vtcO->getY())."\n";
		$fifth_line = "z | ".sprintf("%.2f", $this->_vtcX->getZ())." | ".sprintf("%.2f", $this->_vtcY->getZ())." | ".sprintf("%.2f", $this->_vtcZ->getZ())." | ".sprintf("%.2f", $this->_vtcO->getZ())."\n";
		$sixth_line = "w | ".sprintf("%.2f", $this->_vtcX->getW())." | ".sprintf("%.2f", $this->_vtcY->getW())." | ".sprintf("%.2f", $this->_vtcZ->getW())." | ".sprintf("%.2f", $this->_vtcO->getW());
		return ($first_line.$second_line.$third_line.$fourth_line.$fifth_line.$sixth_line);
	}

	static function doc() {
		return file_get_contents('Matrix.doc.txt')."\n";
	}

}

?>