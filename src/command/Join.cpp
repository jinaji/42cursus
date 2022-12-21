#include "../../include/command/Command.hpp"

void    Command::Join()
{
    Channel instance(_para);

    _caller.addChannel(instance);
    // 서버의 채널 목록도 추가해야함
}