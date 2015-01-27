#include "Vector3DStack.h"
#include <cmath>

Vector3DStack::Vector3DStack(const float xVal, const float yVal, const float zVal){
	coord[0] = xVal;
	coord[1] = yVal;
	coord[2] = zVal;
}

Vector3DStack::Vector3DStack(const Vector3DStack& v){
	coord[0] = v.coord[0];
	coord[1] = v.coord[1];
	coord[2] = v.coord[2];
}

Vector3DStack::~Vector3DStack(){
}

/* Get Magnitude
 * Returns magnitude of vector as a double
 * 
 * Originally used pow(x, 2) but x*x does
 * not add to stack
*/
float Vector3DStack::getMagnitude() const{
	return sqrt((coord[0] * coord[0]) + (coord[1] * coord[1]) + (coord[2] * coord[2]));
}

/*
 If magintude is NULL will return a 
 {0,0,0} vector
 A exception could be thrown but this 
 is slow
*/
Vector3DStack Vector3DStack::unitVector(){
	Vector3DStack newVector;
	float magnitude = getMagnitude();
	if (magnitude != 0){
		newVector.coord[0] = coord[0] / magnitude;
		newVector.coord[1] = coord[1] / magnitude;
		newVector.coord[2] = coord[2] / magnitude;
	}
	return newVector;
}

Vector3DStack Vector3DStack::orthogonalUnitVector(const Vector3DStack& v){
	return (*this % v).unitVector();
}

Vector3DStack Vector3DStack::operator+(const Vector3DStack& v){
	Vector3DStack newVector;
	newVector.coord[0] = (coord[0] + v.coord[0]);
	newVector.coord[1] = (coord[1] + v.coord[1]);
	newVector.coord[2] = (coord[2] + v.coord[2]);
	return newVector;
}

Vector3DStack Vector3DStack::operator-(const Vector3DStack& v){
	Vector3DStack newVector;
	newVector.coord[0] = (coord[0] - v.coord[0]);
	newVector.coord[1] = (coord[1] - v.coord[1]);
	newVector.coord[2] = (coord[2] - v.coord[2]);
	return newVector;
}

Vector3DStack Vector3DStack::operator*(const float scalar){
	Vector3DStack newVector;
	newVector.coord[0] = (coord[0] * scalar);
	newVector.coord[1] = (coord[1] * scalar);
	newVector.coord[2] = (coord[2] * scalar);
	return newVector;
}

/*
 If scalar is 0 will return a 
 {0,0,0} vector
 A exception could be thrown but this 
 is slow
*/
Vector3DStack Vector3DStack::operator/(const float scalar){
	Vector3DStack newVector;
	if (scalar != 0){
		newVector.coord[0] = (coord[0] / scalar);
		newVector.coord[1] = (coord[1] / scalar);
		newVector.coord[2] = (coord[2] / scalar);
	}
	return newVector;
}

float Vector3DStack::operator*(const Vector3DStack& v){
	return ((coord[0] * v.coord[0]) + (coord[1] * v.coord[1]) + (coord[2] * v.coord[2]));
}

Vector3DStack Vector3DStack::operator%(const Vector3DStack& v){
	Vector3DStack newVector;
	newVector.coord[0] = ((coord[1] * v.coord[2]) - (coord[2] * v.coord[1]));
	newVector.coord[1] = ((coord[2] * v.coord[0]) - (coord[0] * v.coord[2]));
	newVector.coord[2] = ((coord[0] * v.coord[1]) - (coord[1] * v.coord[0]));
	return newVector;
}

Vector3DStack& Vector3DStack::operator+=(const Vector3DStack& v){
	coord[0] = coord[0] + v.coord[0];
	coord[1] = coord[1] + v.coord[1];
	coord[2] = coord[2] + v.coord[2];
	return *this;
}

Vector3DStack& Vector3DStack::operator-=(const Vector3DStack& v){
	coord[0] = coord[0] - v.coord[0];
	coord[1] = coord[1] - v.coord[1];
	coord[2] = coord[2] - v.coord[2];
	return *this;
}

Vector3DStack& Vector3DStack::operator/=(const float scalar){
	if (scalar != 0){
		coord[0] = coord[0] / scalar;
		coord[1] = coord[1] / scalar;
		coord[2] = coord[2] / scalar;
	}
	return *this;
}

Vector3DStack& Vector3DStack::operator%=(const Vector3DStack& v){
	coord[0] = ((coord[1] * v.coord[2]) - (coord[2] * v.coord[1]));
	coord[1] = ((coord[2] * v.coord[0]) - (coord[0] * v.coord[2]));
	coord[2] = ((coord[0] * v.coord[1]) - (coord[1] * v.coord[0]));
	return *this;
}

bool Vector3DStack::operator==(const Vector3DStack& v) const {
	return ((coord[0] == v.coord[0]) && (coord[1] == v.coord[1]) && (coord[2] == v.coord[2]));
}

bool Vector3DStack::operator!=(const Vector3DStack& v) const {
	return (!(*this == v));
}

Vector3DStack& Vector3DStack::operator=(const Vector3DStack& v) {
	coord[0] = v.coord[0];
	coord[1] = v.coord[1];
	coord[2] = v.coord[2];
	return *this;
}

Vector3DStack operator*(const float scalar, Vector3DStack& v){
	return (v * scalar);
}

std::ostream& operator<< (std::ostream& outStream, Vector3DStack vector){
	outStream << "{" << vector.getCoordinateX() << ", " <<
		vector.getCoordinateY() << ", " <<
		vector.getCoordinateZ() << "}";

	return outStream;
}