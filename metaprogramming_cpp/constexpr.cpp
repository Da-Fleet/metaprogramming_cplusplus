using namespace std;

constexpr int Fibonacci(int n) {
	return n == 0 || n == 1 ? 0 : Fibonacci(n - 1) + Fibonacci(n - 2);
}

class Point {
public:
	double X, Y;

	constexpr Point(double x, double y) : X(x), Y(y) {}

	constexpr static Point MiddlePoint(Point p1, Point p2) {
		return Point((p1.X + p2.X) / 2, (p1.Y + p2.Y) / 2);
	}
};