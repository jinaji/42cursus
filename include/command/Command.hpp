#ifndef COMMAND_HPP
# define COMMAND_HPP

# include <string>
# include <iostream>

# include "../network/Client.hpp"
# include "../network/Server.hpp"
# include "../network/Channel.hpp"

class Client;
class Server;

class Command
{
	private:
		std::string _cmd;
		std::string _pass;
		std::string _para;
		size_t		_paraNum;
		std::string _parsingPara[9];
		int _mode;

		Client		&_caller;
		Server		&_server;

	public:
	// Command();
	Command(std::string input, std::string pass, Client &caller);
	Command(std::string input, std::string pass, Client &caller, Server &server);
	~Command();

	// void setParanum(std::string input);

	void input_parse(std::string input);
	void para_parse(std::string para);
	void execute();

	public:
	// Client Messages
	void Pass(); // <password>
	void Nick(); // <nickname>
	void User(); // <username> 0 * <realname>
	void Quit(); // <reason>
	void Oper();
	// Channel Operations
	void Join(); // <channel> (<key>)
	void Part(); // <channel> [<reason>]
	void Topic();
	void Names();
	void List(); // <channel> [<elistcond>] <- Clients MUST NOT submit an ELIST condition unless the server has explicitly defined support for that condition with the ELIST token.
	void Invite();
	void Kick(); // <channel> <user> * [<comment>]
	// Server Queries and Commands
	void Mode(); // <target> [<modestring>] [<mode arguments>...]
	// Sending Messages
	void Privmsg(); // <target> <text to be sent>
	void Notice(); // <target> <text to be sent>
	// Numerics
	// void Numerics(int num);
	void Numerics(int num, std::string name ="", std::string other ="");

	bool checkClient(std::string name); // 찾으면 true, 못찾으면 false
	bool checkChannel_server(std::string name);
	bool checkChannel_caller(std::string name);
	bool excute_mode(char mode, char c, char flag = 0);
	void joinMessage(std::string name);
	void privmsgMessage(std::string name, std::string msg, int fd);
	void privmsgMessage(std::string name, std::string msg);
	int  getNickFd(std::string nick, std::list<Client *> clnt);
	void partMessage(std::string name);
	void topciMessage(std::string name, std::string topic);
	void namesMessage(std::string name);
	void noticeMessage(std::string name, std::string msg);
	void kickMessage(std::string name, std::string user);
	void showChannel(std::string name, std::list<Channel> chnl);
	void modeMessage1(std::string name, char flag, std::string user = "");
	void modeMessage2(std::string name, char flag, std::string user = "");
	void modeMessage3(std::string name, char flag, std::string user = "");
	std::string parseComma(std::string origin, size_t &start, size_t &pos);
};

#endif