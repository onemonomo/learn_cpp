// option=0101
#include <iostream>

using namespace std;

class BASE
{
public:
    BASE()
    {
        data = 1;
    }
    int data;
};

int main()
{
    const BASE *tmp = new BASE;
    cout<<tmp->data<<endl;

    BASE *mod = const_cast<BASE *>(tmp);
    mod->data = 2;

    // 这里值变成了2，说明const本质是在编译的时候，禁止通过当前const修饰的指针去修改指针指向地址内容
    // mod只是一个普通的临时指针变量，const_cast相当于将编译禁止const指针给非const指针赋值给解禁了
    cout<<tmp->data<<endl;
    cout<<tmp<<endl<<mod<<endl; // 查看输出可以知道这里两个指针指向的是同一个地址

    return 1; 
}