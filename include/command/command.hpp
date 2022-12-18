#ifndef COMMAND_HPP
# define COMMAND_HPP

class Command
{
	private:

	public:
	Command();

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
};

#endif