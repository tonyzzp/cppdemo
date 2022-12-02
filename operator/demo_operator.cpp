#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class Money
{

public:
    float value;
    Money(float v)
    {
        value = v;
    }

    Money operator-()
    {
        auto m = Money(-value);
        return m;
    }

    // ++i
    Money operator++()
    {
        value++;
        return Money(value);
    }

    // i++
    Money operator++(int)
    {
        auto old = value;
        value++;
        return Money(old);
    }

    Money operator+(int v) const
    {
        return Money(value + v);
    }

    Money
    operator+(const Money &other) const
    {
        return Money(value + other.value);
    }

    Money operator-(const Money &other) const
    {
        return Money(value - other.value);
    }

    Money operator*(const Money &other) const
    {
        return Money(value * other.value);
    }

    Money operator/(const Money &other) const
    {
        return Money(value / other.value);
    }

    bool operator>(const Money &other) const
    {
        return value > other.value;
    }

    bool operator<(const Money &other) const
    {
        return value < other.value;
    }

    bool operator==(const Money &other) const
    {
        return value == other.value;
    }

    bool operator>=(const Money &other) const
    {
        return value >= other.value;
    }

    bool operator<=(const Money &other) const
    {
        return value <= other.value;
    }

    friend ostream &operator<<(ostream &stream, const Money &m)
    {
        stream << m.value;
        return stream;
    }

    friend ostream &operator<<(ostream &stream, const Money *m)
    {
        stream << m->value;
        return stream;
    }

    void operator=(const float v)
    {
        value = v;
    }

    void operator=(const Money &other)
    {
        value = other.value;
    }

    void operator()() const
    {
        cout << "Money.invoke():" << this << endl;
    }

    void operator()(const char *prefix) const
    {
        cout << prefix << this << endl;
    }

    const char operator[](int idx) const
    {
        char s[10];
        sprintf(s, "%f", value);
        if (idx < 0 || idx >= strlen(s))
        {
            return '\7';
        }
        return s[idx];
    }
};

int main()
{
    Money a(100);
    Money b = -a;
    cout << "a.value:" << a.value << endl;
    cout << "b.value:" << b.value << endl;
    cout << "a+3:" << (a + 3).value << endl;
    cout << "a+b:" << (a + b).value << endl;
    cout << "a-b:" << (a - b).value << endl;
    cout << "a*b:" << (a * b).value << endl;
    cout << "a/b:" << (a / b).value << endl;
    cout << "a++:" << (a++).value << endl;
    cout << "a:" << a.value << endl;
    cout << "++:" << (++a).value << endl;
    cout << "a:" << a.value << endl;
    cout << "a<b:" << (a < b) << endl;
    cout << "a>b:" << (a > b) << endl;
    cout << "a==b:" << (a == b) << endl;
    cout << "a>=b:" << (a >= b) << endl;
    cout << "a<=b:" << (a <= b) << endl;
    cout << "cout a:" << a << endl;
    cout << "cout b:" << b << endl;

    a = 3;
    cout << "a=3; a.value:" << a.value << endl;

    a = Money(123);
    cout << "a=Money(123); a.value:" << a.value << endl;

    a();
    b();
    a("a.value:");
    b("b.value:");

    cout << "a[2]:" << a[2] << endl;
    cout << "b[1]:" << b[1] << endl;
    cout << "b[15]:" << b[15] << endl;

    return 0;
}