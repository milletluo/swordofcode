#include <stack>
#include <assert.h>

template <typename T> class StackWithMin
{
public:
    StackWithMin() {}
    virtual ~StackWithMin() {}

    T& top();
    const T& top() const;
	
	void push(const T& value);
	void pop();

	const T& min() const;

	bool empty() const;
	size_t size() const;

private:
	std::stack<T> m_data;
	std::stack<T> m_min;
};	
