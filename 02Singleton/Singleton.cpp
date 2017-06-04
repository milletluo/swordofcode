#include<iostream>
using namespace std;
//懒汉式
class CSingleton
{
public:
    //用GetInstance静态方法实例化对象，并返回
    static CSingleton* GetInstance()
    {
        if(m_pInstance == NULL)
            m_pInstance = new CSingleton();
        return m_pInstance;
    };

private:
    //私有构造函数，只有类内可以调用
    CSingleton(){};
    ~CSingleton(){
        if(m_pInstance == NULL)
            return;
        delete m_pInstance;
        m_pInstance = NULL;
    }
    CSingleton(const CSingleton&);
    CSingleton& operator=(const CSingleton&);
    static CSingleton* m_pInstance;
};

CSingleton* CSingleton::m_pInstance = NULL;//类的静态成员变量需要在类外初始化

int main(int argc,char* argv[])
{
    CSingleton* singleton1 = CSingleton::GetInstance();
    CSingleton* singleton2 = CSingleton::GetInstance();

    if(singleton1 == singleton2)
    {
        cout<<"same"<<endl;
    }
    else
    {
        cout<<"different singleton!"<<endl;
    }
    return 0;
}


