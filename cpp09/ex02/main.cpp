#include "PmergeMe.hpp"

// void lk()
// {
//     system("leaks PmergeMe | grep leaked");
// }

int main(int ac, char **av)
{
    PmergeMe    merge;

    // atexit(lk);
    if (ac == 1)
    {
        std::cout << "Argument count error" << std::endl;
        exit (1);
    }
   
    merge.parseInput(ac, av);

    merge.mergeInsertionSort(merge._vector);
    merge.displayBeforeAfter();
    merge.mergeInsertionSort(merge._deque);
    // merge.mergeInsertionSort(merge._deque, 0, merge._size);
    merge.displayTime();
}