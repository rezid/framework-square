#include <iostream>
#include "algo.hpp"
#include "Number.hpp"

using namespace std;

int main()
{
    int game = 1;

    // Initialization
    State round1(&game);
    Number n1{1};
    unique_ptr<Number> p_num1{new Number(2)};
    unique_ptr<Number> p_num2{new Number(3)};
    round1.push_back(unique_ptr<Number>(&n1));
    round1.push_back(move(p_num1));
    round1.push_back(move(p_num2));

    p_num1 = unique_ptr<Number>(new Number(99));
    State round2(3, move(p_num1));

    State round3{round1};

    State round4;
    round4 = round2;

    cout << "round1:\n";
    for (auto it = round1.begin(); it != round1.end(); ++it)
    {
        (*it)->draw();
        std::cout << "\n";
    }

    cout << "\nround2:\n";
    for (auto it = round2.begin(); it != round2.end(); ++it)
    {
        (*it)->draw();
        std::cout << "\n";
    }

    cout << "\nround3:\n";
    for (auto &e : round3)
    {
        e->draw();
        std::cout << "\n";
    }

    cout << "\nround4:\n";
    for (auto &e : round4)
    {
        e->draw();
        std::cout << "\n";
    }

    //Algorithme

    State algo1{round1};
    unique_ptr<Number> str{new Number(4)};
    algo::replace(algo1.begin() + 1, move(str));

    State algo2{round1};
    algo::swap(algo2.begin(), algo2.end() - 1);

    cout << "\nreplace algorithm:\n";
    for (auto &e : algo1)
    {
        e->draw();
        std::cout << "\n";
    }

    cout << "\nswap algorithm:\n";
    for (auto &e : algo2)
    {
        e->draw();
        std::cout << "\n";
    }

    int i = 0;
    std::cin >> i;
    return 0;
}
