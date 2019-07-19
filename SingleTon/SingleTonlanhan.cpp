#include <iostream>
#include <windows.h>

using namespace std;

//����
/* 
class Singleton
{
private:
    static Singleton* m_Instance;
    Singleton(){
        cout<<"���캯��������"<<endl;
    }
    ~Singleton(){
        cout<<"��������������"<<endl;
    }
public:
    static Singleton* GetInstance(){
        if(m_Instance == NULL)
            m_Instance = new Singleton();
        return m_Instance;
    }
};
*/
//�ոյĴ��������������⣬һ���Ƕ��̵߳�����¿��ܻ����new���ε����������һ���ǳ����˳���û����������������
//��������˾�̬�����������
class Singleton
{
private:
    static Singleton* m_Instance;
    Singleton(){
        cout<<"���캯��������"<<endl;
    }
    ~Singleton(){
        cout<<"��������������"<<endl;
    }
public:
    static Singleton* GetInstance(){
        static Singleton m_s;
        return &m_s;
    }
};
Singleton* Singleton::m_Instance = NULL;

int main(){

    cout << "����ģʽ���ʵ�һ��ǰ" << endl;
    Singleton * s = Singleton::GetInstance();
    cout << "����ģʽ���ʵ�һ�κ�" << endl;
    cout << "����ģʽ���ʵڶ���ǰ" << endl;
    Singleton * s2 = Singleton::GetInstance();//���ᴴ������
    cout << "����ģʽ���ʵڶ��κ�" << endl;
    return 0;
}
