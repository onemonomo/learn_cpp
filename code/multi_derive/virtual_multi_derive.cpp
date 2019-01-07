// option=0001
#include <iostream>

using namespace std;

#define OFF_SET(a, b)  &(((a*)(0))->b)

class BASE1
{
public:
    BASE1()
    {
        base1_data = 1;
    }
    virtual void v_func_base1()
    {
        return;
    }
    int base1_data;
};

class Derive1 : public BASE1
{
    public:
    Derive1(): BASE1() 
    {
        der1_data = 2;
    }
    int der1_data;
};

class BASE2
{
public:
    BASE2()
    {
        base2_data = 3;
    }
    int base2_data;
};

class Derive2 : public BASE1
{
    public:
    Derive2(): BASE1() 
    {
        der2_data = 4;
    }
    int der2_data;
};

class SeqMultiDerive1 : public BASE1, public BASE2
{
    public:
    SeqMultiDerive1(): BASE1(), BASE2()
    {
        seq_mul_der1_data = 5;
    }
    int seq_mul_der1_data;
};

class RectangleMultiDerive1 : public Derive1, public Derive2
{
    public:
    RectangleMultiDerive1(): Derive1(), Derive2()
    {
        rectangle_mul_der1_data = 6;
    }
    int rectangle_mul_der1_data;
};

int main()
{
    int *a = new int;
    cout<<sizeof(a);
    cout<<"基类第一个成员变量偏移\n";
    cout<<OFF_SET(BASE1, base1_data)<<endl;
    cout<<"单继承\n";
    cout<<OFF_SET(Derive1, base1_data)<<endl;
    cout<<OFF_SET(Derive1, der1_data)<<endl;
    cout<<"顺序多继承\n";
    cout<<OFF_SET(SeqMultiDerive1, base1_data)<<endl;
    cout<<OFF_SET(SeqMultiDerive1, base2_data)<<endl;
    cout<<OFF_SET(SeqMultiDerive1, seq_mul_der1_data)<<endl;
    cout<<"菱形多继承\n";
    // 这里编译通过不了，原因是因为RectangleMultiDerive1类里面其实有两个base1_data
    // 从后门的字节偏移也能看出来
    //cout<<OFF_SET(RectangleMultiDerive1, base1_data)<<endl;
    RectangleMultiDerive1 tmp;
    tmp.Derive1::base1_data = 1;
    tmp.Derive2::base1_data = 2;
    cout<<OFF_SET(RectangleMultiDerive1, der1_data)<<endl;
    // 这里跟前面的偏移差了8字节，就是因为Derive2里也有一个base1_data占了4字节
    cout<<OFF_SET(RectangleMultiDerive1, der2_data)<<endl;
    cout<<OFF_SET(RectangleMultiDerive1, rectangle_mul_der1_data)<<endl;

    return 1; 
}