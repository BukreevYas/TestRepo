#include <iostream>

bool isPyth(unsigned a, unsigned b, unsigned c);

int main()
{
    using u_t = unsigned;

    u_t a = 0, b = 0, c = 0;

    size_t count = 0;

    while (std::cin >> a)
    {
        count += isPyth(a, b, c) ? 1 : 0;
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
