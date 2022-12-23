#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include <string>

class Channel
{
	private:
		std::string _name;

		size_t	_participants;
		int		_participantsFd[1024]; // 참여자들 담아두께여

	public:
		Channel(std::string name);
		~Channel();	

		// set
		void    setParticipants(size_t num, int fd);
		
		// get
		std::string getName();
};

#endif