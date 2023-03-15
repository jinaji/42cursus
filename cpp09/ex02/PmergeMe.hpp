#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <sstream>
# include <time.h>
# include <sys/timeb.h>

class PmergeMe 
{
public:
	std::vector<int>	_vector;
	std::deque<int>		_deque;
	static const int			_threshold = 10;
	int	_size;

	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe& obj);
	PmergeMe& operator=(const PmergeMe& obj);

	void parseInput(std::string input);

	void mergeInsertionSort(std::vector<int>& input, int left, int right);
	void mergeInsertionSort(std::deque<int>& input, int left, int right);
	void displayVector();
	void displayDeque();
};

#endif

