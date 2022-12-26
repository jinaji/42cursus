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
		int		_participantsFd[1024]; // 참여자들 담아두께여

	public:
		Channel(std::string name);
		~Channel();

		bool _channelMode[10];

		// set
		void    setParticipants(size_t num, int fd);
		
		// get
		std::string getName();
};

#endif