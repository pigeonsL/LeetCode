#include <iostream>
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
        cout<<"Singleton()..."<<endl;
    }
    ~Singleton(){
        cout<<"~Singleton()..."<<endl;
    }
public:
    static Singleton* GetInstance(){
        static Singleton m_s;//静态对象
        return &m_s;
    }
};
Singleton* Singleton::m_Instance = NULL;

int main(){
    Singleton * s = Singleton::GetInstance();
    Singleton * s2 = Singleton::GetInstance();//不会创建对象
    system("pause");
    return 0;
}
