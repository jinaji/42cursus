#include "PmergeMe.hpp"

void lk()
{
    system("leaks a.out | grep leaked");
}

int main(int ac, char **av)
{
    PmergeMe    merge;
    std::string input;

    atexit(lk);
    if (ac == 1)
    {
        std::cout << "Argument count error" << std::endl;
        exit (1);
    }
   
    for (size_t i = 1; i < ac; i++)
        input += static_cast<std::string>(av[i]) + " ";
    merge.parseInput(static_cast<std::string>(input));

    // merge.mergeInsertionSort(merge._vector, 0, merge._size);
    // merge.mergeInsertionSort(merge._deque, 0, merge._size);
    // merge.displayVector();
    // merge.displayDeque();
}