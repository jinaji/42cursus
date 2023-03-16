#include "PmergeMe.hpp"

void lk()
{
    system("leaks PmergeMe | grep leaked");
}

int main(int ac, char **av)
{
    PmergeMe    merge;

    atexit(lk);
    if (ac == 1)
    {
        std::cout << "Error" << std::endl;
        exit (1);
    }
   try
   {
        merge.parseInput(ac, av);
        merge.mergeInsertionSort(merge._vector);
        merge.displayBeforeAfter();
        merge.mergeInsertionSort(merge._deque);
        merge.displayTime();
   }
   catch(const std::exception& e)
   {
       std::cerr << e.what() << '\n';
   }
}