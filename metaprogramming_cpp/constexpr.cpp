#include <iostream>

using namespace std;

// constexpr int Fibonacci(int n) {
// 	return n == 0 || n == 1 ? 1 : Fibonacci(n - 1) + Fibonacci(n - 2);
// }
// Compile time fibonacci with constexpr
constexpr int Fibonacci(int n) {
	return n == 0 || n == 1 ? 1 : Fibonacci(n - 1) + Fibonacci(n - 2);
}

class Point {
public:
	double X, Y;

	constexpr Point(double x, double y) : X(x), Y(y) {}

	constexpr static Point MiddlePoint(Point p1, Point p2) {
		return Point((p1.X + p2.X) / 2, (p1.Y + p2.Y) / 2);
	}
};

int main()
{
	constexpr int fib = Fibonacci(35);
	cout << fib << endl;

	constexpr Point p1(1, 2);
	constexpr Point p2(3, 4);
	constexpr Point p3 = Point::MiddlePoint(p1, p2);
	cout << p3.X << ", " << p3.Y << endl;
}