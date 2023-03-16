#ifndef BITCOINEXCHANGE_HPP
# define BITCOINTEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <fcntl.h>

class BitcoinExchange
{
    private:
    BitcoinExchange(const BitcoinExchange& obj);
    BitcoinExchange& operator=(const BitcoinExchange& obj);

    public:
    BitcoinExchange();
    ~BitcoinExchange();

    std::map<string, float> _db;

};


#endif