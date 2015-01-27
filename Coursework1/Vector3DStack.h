#include <iostream>
class Vector3DStack{
public:
	Vector3DStack(const float x = 0.0f, const float y = 0.0f, const float z = 0.0f);
	Vector3DStack::Vector3DStack(const Vector3DStack& v);
	~Vector3DStack();
	inline float getCoordinateX() const { return coord[0]; }
	inline float getCoordinateY() const { return coord[1]; }
	inline float getCoordinateZ() const { return coord[2]; }

	float getMagnitude() const;

	inline void setCoordinateX(const float new_x) { coord[0] = new_x; }
	inline void setCoordinateY(const float new_y) { coord[1] = new_y; }
	inline void setCoordinateZ(const float new_z) { coord[2] = new_z; }

	Vector3DStack unitVector();
	Vector3DStack orthogonalUnitVector(const Vector3DStack& v);

	Vector3DStack operator+(const Vector3DStack& v);
	Vector3DStack operator-(const Vector3DStack& v);
	Vector3DStack operator*(const float scalar);
	Vector3DStack operator/(const float scalar);
	float		  operator*(const Vector3DStack& v);
	Vector3DStack operator%(const Vector3DStack& v);

	Vector3DStack& operator+=(const Vector3DStack& v);
	Vector3DStack& operator-=(const Vector3DStack& v);
	Vector3DStack& operator/=(const float scalar);
	Vector3DStack& operator%=(const Vector3DStack& v);

	bool operator==(const Vector3DStack& v) const;
	bool operator!=(const Vector3DStack& v) const;

	Vector3DStack& operator=(const Vector3DStack& v);

private:
	/* Array of Coordinates x,y,z
	* coord[0] = x
	* coord[1] = y
	* coord[2] = z
	*/
	float coord[3];
};

// Prints Vector3DStack in the form {x,y,z}
std::ostream& operator<< (std::ostream& outStream, Vector3DStack vector);

Vector3DStack operator*(const float scalar, Vector3DStack& v);