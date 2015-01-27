#include "Vector3DHeap.h"

Vector3DHeap::Vector3DHeap(const float xVal, const float yVal, const float zVal){
	coord = new float[3];
	coord[0] = xVal;
	coord[1] = yVal;
	coord[2] = zVal;
}

Vector3DHeap::Vector3DHeap(const Vector3DHeap& v){
	coord = new float[3];
	coord[0] = v.coord[0];
	coord[1] = v.coord[1];
	coord[2] = v.coord[2];
}

Vector3DHeap::~Vector3DHeap(){
	delete[] coord;
}

float Vector3DHeap::getMagnitude() const{
	return sqrt((coord[0] * coord[0]) + (coord[1] * coord[1]) + (coord[2] * coord[2]));
}

/*
 If magintude is 0 will return a 
 {0,0,0} vector
 A exception could be thrown but this 
 is slow
*/
Vector3DHeap Vector3DHeap::unitVector(){
	Vector3DHeap newVector;
	float magnitude = getMagnitude();
	if (magnitude != 0){
		newVector.coord[0] = coord[0] / magnitude;
		newVector.coord[1] = coord[1] / magnitude;
		newVector.coord[2] = coord[2] / magnitude;
	}
	return newVector;
}

Vector3DHeap Vector3DHeap::orthogonalUnitVector(const Vector3DHeap& v){
	return (*this % v).unitVector();
}

Vector3DHeap Vector3DHeap::operator+(const Vector3DHeap& v){
	Vector3DHeap newVector;
	newVector.coord[0] = (coord[0] + v.coord[0]);
	newVector.coord[1] = (coord[1] + v.coord[1]);
	newVector.coord[2] = (coord[2] + v.coord[2]);
	return newVector;
}

Vector3DHeap Vector3DHeap::operator-(const Vector3DHeap& v){
	Vector3DHeap newVector;
	newVector.coord[0] = (coord[0] - v.coord[0]);
	newVector.coord[1] = (coord[1] - v.coord[1]);
	newVector.coord[2] = (coord[2] - v.coord[2]);
	return newVector;
}

Vector3DHeap Vector3DHeap::operator*(const float scalar){
	Vector3DHeap newVector;
	newVector.coord[0] = (coord[0] * scalar);
	newVector.coord[1] = (coord[1] * scalar);
	newVector.coord[2] = (coord[2] * scalar);
	return newVector;
}

/*
 If scalar is NULL it will return a 
 {0,0,0} vector
 A exception could be thrown but this 
 is slow
*/
Vector3DHeap Vector3DHeap::operator/(const float scalar){
	Vector3DHeap newVector;
	if (scalar != 0){
		newVector.coord[0] = (coord[0] / scalar);
		newVector.coord[1] = (coord[1] / scalar);
		newVector.coord[2] = (coord[2] / scalar);
	}
	return newVector;
}

float Vector3DHeap::operator*(const Vector3DHeap& v){
	return ((coord[0] * v.coord[0]) + (coord[1] * v.coord[1]) + (coord[2] * v.coord[2]));
}

Vector3DHeap Vector3DHeap::operator%(const Vector3DHeap& v){
	Vector3DHeap newVector;
	newVector.coord[0] = ((coord[1] * v.coord[2]) - (coord[2] * v.coord[1]));
	newVector.coord[1] = ((coord[2] * v.coord[0]) - (coord[0] * v.coord[2]));
	newVector.coord[2] = ((coord[0] * v.coord[1]) - (coord[1] * v.coord[0]));
	return newVector;
}

Vector3DHeap& Vector3DHeap::operator+=(const Vector3DHeap& v){
	coord[0] = coord[0] + v.coord[0];
	coord[1] = coord[1] + v.coord[1];
	coord[2] = coord[2] + v.coord[2];
	return *this;
}

Vector3DHeap& Vector3DHeap::operator-=(const Vector3DHeap& v){
	coord[0] = coord[0] - v.coord[0];
	coord[1] = coord[1] - v.coord[1];
	coord[2] = coord[2] - v.coord[2];
	return *this;
}

Vector3DHeap& Vector3DHeap::operator/=(const float scalar){
	if (scalar != 0){
		coord[0] = coord[0] / scalar;
		coord[1] = coord[1] / scalar;
		coord[2] = coord[2] / scalar;
	}
	return *this;
}

Vector3DHeap& Vector3DHeap::operator%=(const Vector3DHeap& v){
	coord[0] = ((coord[1] * v.coord[2]) - (coord[2] * v.coord[1]));
	coord[1] = ((coord[2] * v.coord[0]) - (coord[0] * v.coord[2]));
	coord[2] = ((coord[0] * v.coord[1]) - (coord[1] * v.coord[0]));
	return *this;
}

bool Vector3DHeap::operator==(const Vector3DHeap& v) const {
	return ((coord[0] == v.coord[0]) && (coord[1] == v.coord[1]) && (coord[2] == v.coord[2]));
}

bool Vector3DHeap::operator!=(const Vector3DHeap& v) const {
	return (!(*this == v));
}

/* 
 The coordinate array may already be
 assigned to some heap memory. If this
 is the case. Delete it to stop memory leaks
*/
Vector3DHeap& Vector3DHeap::operator=(const Vector3DHeap& v) {
	if (coord != NULL){
		delete[] coord;
	}
	coord = new float[3];
	coord[0] = v.coord[0];
	coord[1] = v.coord[1];
	coord[2] = v.coord[2];
	return *this;
}

Vector3DHeap operator*(const float scalar , Vector3DHeap& v){
	return (v * scalar);
}

std::ostream& operator<< (std::ostream& outStream, Vector3DHeap vector){
	outStream << "{" << vector.getCoordinateX() << ", " <<
		vector.getCoordinateY() << ", " <<
		vector.getCoordinateZ() << "}";

	return outStream;
}