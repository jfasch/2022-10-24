#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

class Visitor
{ 
public:
    virtual ~Visitor() {}
    virtual void visit(int) = 0;
};


void visit(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, Visitor* v)
{
    while (begin < end)
        v->visit(*begin++);
}


class Printer : public Visitor
{
public:
    void visit(int elem) override
    {
        std::cout << elem << std::endl;
    }
};

class Accumulator : public Visitor
{
public:
    int sum() const { return _sum; }
    void visit(int elem) override
    {
        _sum += elem;
    }
private:
    int _sum = 0;
};

int main()
{
    std::vector<int> elems{1,2,3,4,5,6};

    std::cout << "Printer" << std::endl;
    Printer p;
    visit(elems.begin(), elems.end(), &p);

    std::cout << "Accumulator" << std::endl;
    Accumulator a;
    visit(elems.begin(), elems.end(), &a);
    std::cout << a.sum() << std::endl;

    std::cout << "for_each mit lambda" << std::endl;
    int sum = 0;
    std::for_each(elems.begin(), elems.end(), [&sum](int elem){sum += elem;});
    std::cout << sum << std::endl;

    std::cout << "accumulate mit lambda" << std::endl;
    std::cout << std::accumulate(elems.begin(), elems.end(), 0, [](int l, int r){return l+r;}) << std::endl;
    std::cout << std::accumulate(elems.begin(), elems.end(), 0) << std::endl;

    return 0;
}
