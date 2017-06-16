#include <stack>
using namespace std;

template <typename T> class CQueue
{
public:
	CQueue(void);
	~CQueue(void);

	void appendTail(const T& node);
	T deleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;
};
