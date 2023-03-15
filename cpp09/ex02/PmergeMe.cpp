#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& obj)
{
    *this = obj;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj)
{
    this->_vector = obj._vector;
    this->_deque = obj._deque;
    this->_size = obj._size;
    return *this;
}

void PmergeMe::parseInput(std::string input)
{
    std::stringstream ss(input);
    int num;

    while (ss >> num)
    {
        _vector.push_back(num);
        _deque.push_back(num);
    }
}

void PmergeMe::mergeInsertionSort(std::vector<int>& input, int left, int right)
{

}

void PmergeMe::mergeInsertionSort(std::deque<int>& input, int left, int right)
{

}

void PmergeMe::displayVector()
{

}

void PmergeMe::displayDeque()
{

}
