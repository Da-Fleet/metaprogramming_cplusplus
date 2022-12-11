using namespace std;

constexpr int Fibonacci(int n) {
	return n == 0 || n == 1 ? 1 : Fibonacci(n - 1) + Fibonacci(n - 2);
}