#include <iostream>
#include <limits>

bool isPyth(unsigned a, unsigned b, unsigned c);

int main()
{
    using u_t = unsigned;

    u_t a = 0, b = 0, c = 0;

    std::cin >> c >> b;

    size_t count = 0;

    while (std::cin >> a)
    {
        try
        {
            count += isPyth(a, b, c) ? 1 : 0;
            c = b;
            b = a;
        }
        catch(const std::overflow_error& e)
        {
            std::cerr << "Some of the entered numbers are too big.\n";
            return 2;
        }
    }

    if (std::cin.eof())
    {
        std::cout << count;
        std::cout << '\n';
    }
    else if (std::cin.fail())
    {
        std::cerr << "Input error.\n";
        return 1;
    }
}

bool isPyth(unsigned a, unsigned b, unsigned c)
{
    unsigned u_max = std::numeric_limits<unsigned>::max();

    if (a > u_max / a || b > u_max / b || c > u_max / c)
    {
        throw std::overflow_error("isPyth mul");
    }

    unsigned aSqr = a * a;
    unsigned bSqr = b * b;
    unsigned cSqr = c * c;

    if (bSqr > u_max - cSqr || aSqr > u_max - cSqr || aSqr > u_max - bSqr)
    {
        throw std::overflow_error("isPyth add");
    }

    bool p = aSqr == bSqr + cSqr;
    p = p || (bSqr == aSqr + cSqr);
    p = p || (cSqr == aSqr + bSqr);

    return p;
}
