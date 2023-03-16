#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <sstream>
# include <ctime>
# include <sys/time.h>

class PmergeMe 
{
public:
	std::vector<int>	_vector;
	std::deque<int>		_deque;
	static const int			_threshold = 10;
	int	_size;
	double _vectorTime;
	double _dequeTime;

	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe& obj);
	PmergeMe& operator=(const PmergeMe& obj);

	void parseInput(int ac, char **av);
	ssize_t getTime();

	void displayBeforeAfter();
	void displayTime();


	void mergeSort(std::vector<int>& input, int left, int mid, int right);
	void insertionSort(std::vector<int>& input, int left, int right);
	void mergeInsertionSort(std::vector<int>& input, int left, int right);
	void mergeInsertionSort(std::vector<int>& input);


	void mergeSort(std::deque<int>& input, int left, int mid, int right);
	void insertionSort(std::deque<int>& input);
	void mergeInsertionSort(std::deque<int>& input, int left, int right);
	void mergeInsertionSort(std::deque<int>& input);

	public:
	class argumentError : public std::exception
	{
		public:
		const char* what() const throw()
		{
			return ("Error");
		}
	};
};

#endif

