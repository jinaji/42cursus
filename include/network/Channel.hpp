#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include <string>

enum Channel_mode
{
	channel_o = 0,
	channel_p,
	channel_s,
	channel_i,
	channel_t,
	channel_m,
	channel_v,
	channel_l,
	channel_b,
	channel_k
};

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

		bool _channelMode[10];

		// set
		void    setParticipants(size_t num, int fd);
		void	setPass(std::string pass);
		
		// get
		size_t		getParticipants();
		std::string getName();
		std::string getPass();
};

#endif