//定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。

class Solution {
public:
    void push(int value) {
        m_data.push(value);
        if(m_min.size()==0||value<=m_min.top()){
            m_min.push(value);
        }
    }
    void pop() {
        if(m_min.size()!=0&&m_data.top()==m_min.top())
            m_min.pop();
        if(m_data.size()!=0)
            m_data.pop();
    }
    int top() {
        return m_data.top();
    }
    int min() {
        return m_min.top();
    }
    stack<int> m_data;
    stack<int> m_min;
};
