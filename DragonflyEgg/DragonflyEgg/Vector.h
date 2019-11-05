#ifndef __VECTOR_H__
#define __VECTOR_H__

namespace df {
	class Vector {
	private: 
		float m_x;
		float m_y;
	public:
		//create vector with (x, y)
		Vector(float init_x, float init_y);

		//default 2d (x, y) is (0, 0)
		Vector();

		//get + set horizontal component
		void setX(float new_x);
		float getX() const;

		//get + set vertical component
		void setY(float new_y);
		float getY() const;

		//set both x + y
		void setXY(float new_x, float new_y);

		//return magnitude of vector
		float getMagnitude() const;

		//normalize vector
		void normalize();

		//scale vector
		void scale(float s);

		//add 2 vectors and return sum
		Vector operator+(const Vector &other) const;

		//add 2 vectors and return sum
		Vector operator-(const Vector& other) const;

		//add 2 vectors and return sum
		Vector operator*(const Vector& other) const;

		//add 2 vectors and return sum
		Vector operator/(const Vector& other) const;

		//add 2 vectors and return sum
		bool equals(const Vector& other) const;
	};
}

#endif
