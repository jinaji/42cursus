#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include <string>

class Channel
{
	private:
		std::string _name;

		size_t	_participants;
		std::string _chnlPass;
		int		_participantsFd[1024]; // 참여자들 담아두께여
		std::string _topic;

	public:
		Channel();
		Channel(std::string name);
		~Channel();	

		// set
		void    setParticipants(size_t num, int fd);
		void	setPass(std::string pass);
		
		// get
		size_t		getParticipants();
		std::string getName();
		std::string getPass();
};

#endif