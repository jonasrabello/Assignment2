#ifndef VECTOR_
#define VECTOR_

struct Vec3 {

	int x;
	int y;
	int z;

	Vec3() {
		x = 0;
		y = 0;
		z = 0;
	}

	Vec3(int x_, int y_, int z_) {
		x = x_;
		y = y_;
		z = z_;
	}

	void Set(int x_, int y_, int z_) {
		x = x_;
		y = y_;
		z = z_;
	}

	void SetZero() {
		x = 0;
		y = 0;
		z = 0;
	}

	void operator += (const Vec3& v) {
		x += v.x;
		y += v.y;
		z += v.z;
	}

	Vec3 operator + (const Vec3& v) {
		return Vec3(x + v.x, y + v.y, z + v.z);
	}
};
#endif // !VECTOR_