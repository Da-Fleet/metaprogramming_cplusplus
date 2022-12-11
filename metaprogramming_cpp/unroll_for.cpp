using namespace std;

template<int start, int end, int inc>
struct _for {
	static void run() {
		/* Write your code here!!! */
		_for<start + inc, end, inc >::run();
	}
};

template<int end, int inc>
struct _for<end, end, inc > {
	static void run() {
		return;
	}
};