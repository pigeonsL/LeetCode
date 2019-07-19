//饿汉模式,不存在线程安全问题
class Singleton
{
protected:
    Singleton(){} // 设置为保护便于被继承
private:
    Singleton(const Singleton& s) = delete; // 防拷贝(注:delete是c++11中的语法),将该函数禁用
    Singleton* operator=(const Singleton& s) = delete; // 防赋值
    static Singleton* p; // 指向单例对象的指针

public:
    static Singleton* getInstance(){
        return p;
    }
};

Singleton* Singleton::p = new Singleton(); // 第一次常见类就给分配资源
