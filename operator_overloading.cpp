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
	friend Point operator+(const Point& pos1, const Point& pos2);
	friend Point operator-(const Point& pos1, const Point& pos2);
	friend bool operator==(const Point& pos1, const Point& pos2);
	friend bool operator!=(const Point& pos1, const Point& pos2);

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

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);



	return 0;
}