#pragma once

#include <map>

class Context
{
public:
    Context() = default;
    Context(const Context&) = delete;
    Context& operator=(const Context&) = delete;

    int get(const std::string& variablename) const
    {
        auto found = _names.find(variablename);
        if (found != _names.end())
            return found->second;
        return 0;
    }

    void set(const std::string& variablename, int value)
    {
        _names[variablename] = value;
    }

private:
    std::map<std::string, int> _names;
};

class Expression
{
public:
    virtual ~Expression() {}
    virtual int evaluate() = 0;
};

class Literal : public Expression
{
public:
    Literal(int value) : _value(value) {}
    int evaluate() override
    {
        return _value;
    }
private:
    int _value;
};

template <typename FCN>
class ArithmeticBinaryOperator : public Expression
{
public:
    ArithmeticBinaryOperator(Expression& lhs, Expression& rhs)
    : _lhs(lhs), _rhs(rhs) {}

    int evaluate() override
    {
        FCN fcn;
        return fcn(_lhs.evaluate(), _rhs.evaluate());
    }

private:
    Expression& _lhs;
    Expression& _rhs;
};

using Addition = ArithmeticBinaryOperator<std::plus<int>>;
using Subtraction = ArithmeticBinaryOperator<std::minus<int>>;
using Multiplication = ArithmeticBinaryOperator<std::multiplies<int>>;
using Division = ArithmeticBinaryOperator<std::divides<int>>;

class BinaryOperator : public Expression
{
public:
    BinaryOperator(Expression& lhs, Expression& rhs, 
                   std::function<int(int, int)> fcn)
    : _lhs(lhs), _rhs(rhs), _fcn(fcn) {}

    int evaluate() override
    {
        return _fcn(_lhs.evaluate(), _rhs.evaluate());
    }

private:
    Expression& _lhs;
    Expression& _rhs;
    std::function<int(int, int)> _fcn;
};

class Variable : public Expression
{
public:
    Variable(Context& context, const std::string& name)
    : _context(context), 
      _name(name) {}

    int evaluate() override
    {
        return _context.get(_name);
    }

    void set(int value)
    {
        _context.set(_name, value);
    }

private:
    Context& _context;
    std::string _name;
};

class Assignment : public Expression
{
public:
    Assignment(Variable& variable, Expression& rhs)
    : _variable(variable), 
      _rhs(rhs) {}

    int evaluate() override
    {
        int value = _rhs.evaluate();
        _variable.set(value);
        return value;
    }

private:
    Variable& _variable;
    Expression& _rhs;
};
