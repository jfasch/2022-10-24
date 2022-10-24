#include <iostream>
#include <cstring>


class Interface
{
public:
    virtual ~Interface() {}
    virtual void doit() = 0;
};

class Implementation : public Interface
{
public:
    Implementation(const std::string& woswasi)
    : _buffer(new char[woswasi.size() + 1])
    {
        strcpy(_buffer, woswasi.c_str());
    }

    ~Implementation()
    {
        delete[] _buffer;
    }

    void doit() override
    {
        std::cout << "Implementation::doit(): " << _buffer << std::endl;
    }

private:
    char* _buffer;
};


int main()
{
    Interface* interface = new Implementation("Hallo!");

    // ab hier nur mehr zugriff via Interface
    interface->doit();

    delete interface;

    return 0;
}
