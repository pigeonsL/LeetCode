#include <iostream>
#include <windows.h>

using namespace std;

//懒汉
/* 
class Singleton
{
private:
    static Singleton* m_Instance;
    Singleton(){
        cout<<"构造函数。。。"<<endl;
    }
    ~Singleton(){
        cout<<"析构函数。。。"<<endl;
    }
public:
    static Singleton* GetInstance(){
        if(m_Instance == NULL)
            m_Instance = new Singleton();
        return m_Instance;
    }
};
*/
//刚刚的代码中有两个问题，一个是多线程的情况下可能会出现new两次的情况。另外一个是程序退出后没有运行析构函数。
//下面采用了静态对象来解决。
class Singleton
{
private:
    static Singleton* m_Instance;
    Singleton(){
        cout<<"构造函数。。。"<<endl;
    }
    ~Singleton(){
        cout<<"析构函数。。。"<<endl;
    }
public:
    static Singleton* GetInstance(){
        static Singleton m_s;
        return &m_s;
    }
};
Singleton* Singleton::m_Instance = NULL;

int main(){

    cout << "单例模式访问第一次前" << endl;
    Singleton * s = Singleton::GetInstance();
    cout << "单例模式访问第一次后" << endl;
    cout << "单例模式访问第二次前" << endl;
    Singleton * s2 = Singleton::GetInstance();//不会创建对象
    cout << "单例模式访问第二次后" << endl;
    return 0;
}
