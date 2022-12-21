#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include <string>

class Channel
{
    private:
        std::string _name;

        size_t _participants;

    public:
        Channel(std::string name);
        ~Channel();

        // set
        void    setParticipants(size_t num);
        
        // get
        std::string getName();
};

#endif