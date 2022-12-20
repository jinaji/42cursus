#include "../../include/command/Command.hpp"

void Command::Pass()
{
    // std::cout << "pass: " << _pass << ", para: " << _para << ";" ;
    if (_pass.compare(_para))
    {
        // 틀렸다는 메세지
        std::cout << "NO!" << std::endl;
    }
    else
        _caller.setPass(_pass);
        // 클라이언트의 PASS정보 통과
}

// 서버 비번/ 클라 비번 구별 필요