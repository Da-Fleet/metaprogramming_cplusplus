using namespace std;

constexpr int Fibonacci(int n) {
	return n == 0 || n == 1 ? 1 : Fibonacci(n - 1) + Fibonacci(n - 2);
}

class Point {
public:
	double X, Y;
	constexpr Point(double x, double y) : X(x), Y(y) {}
};