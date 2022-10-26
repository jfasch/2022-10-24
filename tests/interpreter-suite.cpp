#include <gtest/gtest.h>

#include <expression.h>


TEST(interpreter_suite, literal)
{
    Literal le(42);
    Expression* e = &le;            // <--- Literal *is-a* Expression
    ASSERT_EQ(e->evaluate(), 42);   // <--- ... and is evaluated as such
}

TEST(interpreter_suite, addition)
{
    Literal lhs(1);
    Expression& e_lhs = lhs;

    Literal rhs(2);
    Expression& e_rhs = rhs;

    Addition add(e_lhs, e_rhs);       // <--- adds two *Expression* values (not only Literals)
    Expression& e_add = add;          // <--- Addition *is-a* Expression
    ASSERT_EQ(e_add.evaluate(), 3);   // <--- ... and is evaluated as such
}

TEST(interpreter_suite, subtraction)
{
    Literal lhs(1);
    Expression& e_lhs = lhs;

    Literal rhs(2);
    Expression& e_rhs = rhs;

    Subtraction sub(e_lhs, e_rhs);
    Expression& e_sub = sub;
    
    ASSERT_EQ(e_sub.evaluate(), -1);
}

TEST(interpreter_suite, multiplication)
{
    Literal lhs(2);
    Expression& e_lhs = lhs;

    Literal rhs(3);
    Expression& e_rhs = rhs;

    Multiplication mul(e_lhs, e_rhs);
    Expression& e_mul = mul;
    
    ASSERT_EQ(e_mul.evaluate(), 6);
}

TEST(interpreter_suite, division)
{
    Literal lhs(3);
    Expression& e_lhs = lhs;

    Literal rhs(2);
    Expression& e_rhs = rhs;

    Division div(e_lhs, e_rhs);
    Expression& e_div = div;
    
    ASSERT_EQ(e_div.evaluate(), 1);
}

TEST(interpreter_suite, binary_operator)
{
    Literal lhs(3);
    Expression& e_lhs = lhs;

    Literal rhs(5);
    Expression& e_rhs = rhs;

    BinaryOperator teifl(e_lhs, e_rhs, [](int lhs, int rhs){ return (lhs+rhs)/2;});
    ASSERT_EQ(teifl.evaluate(), 4);
}

TEST(interpreter_suite, combined_arith)
{
    Literal l7(7);
    Literal l3(3);
    Literal l1(1);

    Addition a_7_plus_3(l7, l3);
    Subtraction s_3_minus_1(l3, l1);

    Multiplication total(a_7_plus_3, s_3_minus_1);

    ASSERT_EQ(total.evaluate(), 20);
}

TEST(interpreter_suite, variable_not_set)
{
    Context context;              // <--- e.g. local or global scope (if we had functions)
    Variable v(context, "i");     // <--- v lives in context, under the name "i"
    ASSERT_EQ(v.evaluate(), 0);   // <--- v has never been assigned to -> default value 0
}

TEST(interpreter_suite, variable_assignment)
{
    Context context;

    Variable v(context, "i");
    Literal l(42);
    Assignment ass(v, l);               // <--- Assignment object created (but not yet evaluated)

    ASSERT_EQ(ass.evaluate(), 42);      // <--- Assignment evaluation: "i = 42" has value 42 (as in C)
    ASSERT_EQ(context.get("i"), 42);    // <--- variable has made it into context
    ASSERT_EQ(v.evaluate(), 42);        // <--- variable now has a defined value
}

TEST(interpreter_suite, variable_used_as_expression)
{
    Context context;

    Variable v1(context, "i");
    Literal l(42);
    Assignment ass_v1(v1, l);
    ass_v1.evaluate();             // <--- "i = 42" (not consuming assignment as expression)

    Variable v2(context, "j");
    Assignment ass_v2(v2, v1);
    ass_v2.evaluate();             // <--- "i = j"

    ASSERT_EQ(v2.evaluate(), 42);
    ASSERT_EQ(v2.evaluate(), v1.evaluate());
}
