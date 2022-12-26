#include "../../include/command/Command.hpp"

/*

  JOIN #foobar                    ; join channel #foobar.

  JOIN &foo fubar                 ; join channel &foo using key "fubar".

  JOIN #foo,&bar fubar            ; join channel #foo using key "fubar"
                                  and &bar using no key.

  JOIN #foo,#bar fubar,foobar     ; join channel #foo using key "fubar".
                                  and channel #bar using key "foobar".

  JOIN #foo,#bar                  ; join channels #foo and #bar.

  ?????
  _para 뒤에 개행 띠고 채널 이름으로 넣어야 list에서 편할듯해염
*/

void    Command::Join()
{
    Channel instance(_para);

    _caller.addChannel(instance);
    _server.getChannel().push_back(instance);
    // 서버의 채널 목록도 추가해야함
}