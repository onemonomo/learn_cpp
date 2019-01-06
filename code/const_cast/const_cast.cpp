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

    return 1; 
}