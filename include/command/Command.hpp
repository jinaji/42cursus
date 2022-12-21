#ifndef COMMAND_HPP
# define COMMAND_HPP

# include <string>
# include <iostream>

# include "../network/Client.hpp"
# include "../network/Channel.hpp"

class Client;

class Command
{
	private:
		std::string _cmd;
		std::string _pass;
		std::string _para;
		size_t		_paraNum;
		std::string _parsingPara[9];
		Client		_caller;

	public:
	// Command();
	Command(std::string input, std::string pass, Client caller);
	// Command(std::string input, std::string pass);
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
	void Oper();
	void Quit(); // <reason>
	// Channel Operations
	void Join(); // <channel> (<key>)
	void Part(); // <channel> [<reason>]
	void Topic();
	void Names();
	void List(); // <channel> [<elistcond>] <- Clients MUST NOT submit an ELIST condition unless the server has explicitly defined support for that condition with the ELIST token.
	void Invite();
	void Kick(); // <channel> <user> * [<comment>]
	// Server Queries and Commands
	void Help();
	void Mode(); // <target> [<modestring>] [<mode arguments>...]
	// Sending Messages
	void Notice(); // <target> <text to be sent>
	void Privmsg(); // <target> <text to be sent>
	// User-Based Queries
	void Who(); // <mask> <- channel name / exact nickname / mask pattern? 읽어보면 알 듯
	// Numerics
	void Numerics(int num);
};

#endif