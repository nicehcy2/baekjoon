#include <iostream>
#pragma warning(disable:4996)
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0)
		:xpos(x), ypos(y)
	{ }
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}

	Point& operator+=(const Point& ref) {
		xpos += ref.xpos;
		ypos += ref.ypos;
		return *this;
	}
	Point& operator-=(const Point& ref) {
		xpos -= ref.xpos;
		ypos -= ref.ypos;
		return *this;
	}
	Point operator+(const Point& ref) {
		Point pos(xpos + ref.xpos, ypos + ref.ypos);
		return pos;
	}
	Point operator-(const Point& ref) {
		Point pos(xpos - ref.xpos, ypos - ref.ypos);
		return pos;
	}
	Point& operator++() {
		xpos += 1;
		ypos + 1;
		return *this;
	}
	Point& operator--() {
		xpos -= 1;
		ypos -= 1;
		return*this;
	}
	const Point operator++(int) {
		const Point retobj(xpos, ypos);
		xpos += 1;
		ypos += 1;
		return retobj;
	}
	const Point operator--(int) {
		const Point retobj(xpos, ypos);
		xpos -= 1;
		ypos -= 1;
		return retobj;
	}
	ostream& operator<<(ostream& os) {
		os << '[' << xpos << ", " << ypos << ']' << endl;
	}
	istream& operator>>(istream& is) {
		is >> xpos >> ypos;
		return is;
	}


	friend Point operator+(const Point& pos1, const Point& pos2);
	friend Point operator-(const Point& pos1, const Point& pos2);
	friend Point& operator++(Point& ref);
	friend Point& operator--(Point& ref);
	friend const Point operator++(Point& ref, int);
	friend const Point operator--(Point& ref, int);
	friend bool operator==(const Point& pos1, const Point& pos2);
	friend bool operator!=(const Point& pos1, const Point& pos2);
	friend ostream& operator<<(ostream&, const Point&);
	friend istream& operator>>(istream&, const Point&);
};

Point operator+(const Point& pos1, const Point& pos2) {
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}

Point operator-(const Point& pos1, const Point& pos2)
{
	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
	return pos;
}

bool operator==(const Point& pos1, const Point& pos2)
{
	if (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos) {
		return true;
	}
	else
		return false;
}

bool operator!=(const Point& pos1, const Point& pos2) {
	return !(pos1 == pos2);
}

Point& operator++(Point& ref) {
	ref.xpos += 1;
	ref.ypos += 1;
	return ref;
}

Point& operator--(Point& ref) {
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}

const Point operator++(Point& ref, int) {
	const Point retobj(ref);
	ref.xpos += 1;
	ref.ypos + 1;
	return ref;
}

const Point operator--(Point& ref, int) {
	const Point retobj(ref);
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}

ostream& operator<<(ostream& os, const Point& pos) {
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

istream& operator>>(istream& is, const Point& pos) {
	is >> pos.xpos >> pos.ypos;
	return is;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);



	return 0;
}