#include "../../include/command/Command.hpp"

// 이미 user 정보가 있으면 -> 462
// 유효한 인자가 안들어오면 -> 461 // need more param

void Command::User()
{
	if (_caller.getnickState() == false)
		return ;
	if (_paraNum < 4) // != 4 ... realname 엔 space 있을수도 있음 
	{
		this->Numerics(461);
		return ;
	}
	if (!_caller.getUser().empty() || !_caller.getReal().empty()) // 테스트할때 얘 빼야댐
	{
		this->Numerics(462);
		return ;
	}
	if (_parsingPara[1] != "0" || _parsingPara[2] != "*" || 1 > _parsingPara[0].length())
	{
		this->Numerics(461);
		return ;
	}
	if ( _parsingPara[0].length() > 9)
		_parsingPara[0].resize(9);
	_caller.setUser(_parsingPara[0]);
	_caller.setReal(_parsingPara, _paraNum);
	_caller.setuserState(true);
}