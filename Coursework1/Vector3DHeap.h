#include <iostream>
class Vector3DHeap{
public:
	Vector3DHeap(const float x = 0.0f, const float y = 0.0f, const float z = 0.0f);
	Vector3DHeap(const Vector3DHeap& v);
	~Vector3DHeap();

	inline float getCoordinateX() const { return coord[0]; }
	inline float getCoordinateY() const { return coord[1]; }
	inline float getCoordinateZ() const { return coord[2]; }
	float getMagnitude() const;

	inline void setCoordinateX(const float new_x) { coord[0] = new_x; }
	inline void setCoordinateY(const float new_y) { coord[1] = new_y; }
	inline void setCoordinateZ(const float new_z) { coord[2] = new_z; }

	Vector3DHeap unitVector();
	Vector3DHeap orthogonalUnitVector(const Vector3DHeap& v);

	Vector3DHeap operator+(const Vector3DHeap& v);
	Vector3DHeap operator-(const Vector3DHeap& v);
	Vector3DHeap operator*(const float scalar);
	Vector3DHeap operator/(const float scalar);
	float		 operator*(const Vector3DHeap& v);
	Vector3DHeap operator%(const Vector3DHeap& v);

	Vector3DHeap& operator+=(const Vector3DHeap& v);
	Vector3DHeap& operator-=(const Vector3DHeap& v);
	Vector3DHeap& operator/=(const float scalar);
	Vector3DHeap& operator%=(const Vector3DHeap& v);

	bool operator==(const Vector3DHeap& v) const;
	bool operator!=(const Vector3DHeap& v) const;

	Vector3DHeap& operator=(const Vector3DHeap& v);

private:
	float* coord;
};

// Allow int * vector3D
Vector3DHeap operator*(const float scalar, Vector3DHeap& v);

std::ostream& operator<< (std::ostream& outStream, Vector3DHeap vector);