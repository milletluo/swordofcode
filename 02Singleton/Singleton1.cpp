#include<iostream>
using namespace std;
//饿汉式
class CSingleton
{
public:
    //用GetInstance静态方法实例化对象，并返回
    static CSingleton* GetInstance()
    {
        //静态局部变量在第一次使用时初始化，并不会销毁直到程序退出
        static CSingleton instance;
        return &instance;
    };

private:
    //私有构造函数，只有类内可以调用
    CSingleton(){};
    CSingleton(const CSingleton&);
    CSingleton& operator=(const CSingleton&);
};


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


