#ifndef COMMAND_HPP
# define COMMAND_HPP

# include <string>
# include <iostream>

# include "../network/Client.hpp"

class Client;

class Command
{
	private:
		std::string _cmd;
		std::string _para;
		std::string _pass;
		Client		_caller;

	public:
	Command();
	Command(std::string input, std::string pass, Client caller);
	Command(std::string input, std::string pass);
	void execute();

	public:
	void Authenticate(); // ??
	void Pass(); // <password>
	void Nick(); // <nickname>
	void User(); // <username> 0 * <realname>
	void Quit(); // <reason>
	void Mode(); // <target> [<modestring>] [<mode arguments>...]
	void List(); // <channel> [<elistcond>] <- Clients MUST NOT submit an ELIST condition unless the server has explicitly defined support for that condition with the ELIST token.
	void Join(); // <channel> (<key>)
	void Part(); // <channel> [<reason>]
	void Who(); // <mask> <- channel name / exact nickname / mask pattern? 읽어보면 알 듯
	void Kick(); // <channel> <user> * [<comment>]
	void Notice(); // <target> <text to be sent>
	void Privmsg(); // <target> <text to be sent>
	void Invite();
	void Help();
	void Names();
	void Topic();
	void Numerics(int num);
};

#endif