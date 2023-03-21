#include "PmergeMe.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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


/* utils */


void PmergeMe::parseInput(int ac, char **av)
{
    std::string input;
    int num;

    for (int i = 1; i < ac; i++)
        input += static_cast<std::string>(av[i]) + " ";

    std::stringstream ss(input);

    while (ss >> num)
    {
        if (num < 0)
            throw (argumentError());
        _vector.push_back(num);
        _deque.push_back(num);
    }
    _size = _vector.size();
    if (ac - 1 != _size)
        throw (argumentError());
}

ssize_t	PmergeMe::getTime(void)
{
	struct timeval	time;
	ssize_t			usec;

	gettimeofday(&time, 0);
    usec = time.tv_sec * 1000 + time.tv_usec ;
	return (usec);
}


void PmergeMe::displayBeforeAfter()
{
    std::cout << "Before: ";
    for (std::deque<int>::iterator it = _deque.begin(); it != _deque.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "After:  ";
    for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::displayTime()
{
    std::cout << "Time to process a range of " << _size << " elements with std::vector : " << _vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _size << " elements with std::deque : " << _dequeTime << " us" << std::endl;
}



/* vector */



void PmergeMe::mergeSort(std::vector<int>& input, int left, int mid, int right)
{
    std::vector<int> tmp(right - left + 1);
    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right)
    {
        if (input[i] <= input[j])
        {
            tmp[k] = input[i];
            i++;
        }
        else
        {
            tmp[k] = input[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        tmp[k] = input[i];
        i++;
        k++;
    }
    while (j <= right)
    {
        tmp[k] = input[j];
        j++;
        k++;
    }
    for (int l = 0; l < k; l++)
    {
        input[left + l] = tmp[l];
    }
}

void PmergeMe::insertionSort(std::vector<int>& input, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int key = input[i];
        int j = i - 1;
        while (j >= left && input[j] > key)
        {
            input[j + 1] = input[j];
            j--;
        }
        input[j + 1] = key;
    }
}

void PmergeMe::mergeInsertionSort(std::vector<int>& input, int left, int right)
{
    int threshold = 10;

    if (left < right)
    {
        if (right - left <= threshold) // 임계점 이하 삽입정렬
            insertionSort(input, left, right);
        else
        {
            int mid = (left + right) / 2;
            mergeInsertionSort(input, left, mid);
            mergeInsertionSort(input, mid + 1, right);
            mergeSort(input, left, mid, right);
        }
    }

}

void PmergeMe::mergeInsertionSort(std::vector<int>& input)
{
    ssize_t startTime = getTime();
    mergeInsertionSort(input, 0, _size - 1);
    ssize_t endTime = getTime();
    if (endTime < startTime)
        endTime += 1000000;
    _vectorTime = static_cast<double>(endTime - startTime) / 100000.0;
}



/* deque */



void PmergeMe::mergeSort(std::deque<int>& input, int left, int mid, int right)
{
    std::deque<int> tmp;
    int i = left;
    int j = mid + 1;
    while (i <= mid && j <= right)
    {
        if (input[i] < input[j])
        {
            tmp.push_back(input[i]);
            i++;
        }
        else
        {
            tmp.push_back(input[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        tmp.push_back(input[i]);
        i++;
    }
    while (j <= right)
    {
        tmp.push_back(input[j]);
        j++;
    }

    int l = left;
    for (std::deque<int>::iterator it = tmp.begin(); it != tmp.end(); it++)
    {
        input[l] = *it;
        l++;
    }

}
void PmergeMe::insertionSort(std::deque<int>& input)
{
    for (unsigned int i = 1; i < input.size(); i++) {
        int key = input[i];
        int j = i - 1;
        while (j >= 0 && input[j] > key) {
            input[j+1] = input[j];
            j--;
        }
        input[j+1] = key;
    }
}


void PmergeMe::mergeInsertionSort(std::deque<int>& input, int left, int right)
{
    int threshold = 10;

    if (right - left + 1 <= threshold)
        insertionSort(input);
    else
    {
        int mid = (left + right) / 2;
        mergeInsertionSort(input, left, mid);
        mergeInsertionSort(input, mid + 1, right);
        mergeSort(input, left, mid, right);
    }
}

void PmergeMe::mergeInsertionSort(std::deque<int>& input)
{
    ssize_t startTime = getTime();
    mergeInsertionSort(input, 0, _size - 1);
    ssize_t endTime = getTime();
    if (endTime < startTime)
        endTime += 1000000;
    _dequeTime = static_cast<double>(endTime - startTime) / 100000.0;
}
