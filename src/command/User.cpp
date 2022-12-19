#include "../../include/Command.hpp"

// https://modern.ircdocs.horse/#authenticate-message

/*
USER message
     Command: USER
  Parameters: <username> 0 * <realname>
The USER command is used at the beginning of a connection to specify the username and realname of a new user.

It must be noted that <realname> must be the last parameter because it may contain SPACE (' ', 0x20) characters, and should be prefixed with a colon (:) if required.

Servers MAY use the Ident Protocol to look up the ‘real username’ of clients. If username lookups are enabled and a client does not have an Identity Server enabled, the username provided by the client SHOULD be prefixed by a tilde ('~', 0x7E) to show that this value is user-set.

The maximum length of <username> may be specified by the USERLEN RPL_ISUPPORT parameter. If this length is advertised, the username MUST be silently truncated to the given length before being used. The minimum length of <username> is 1, ie. it MUST NOT be empty. If it is empty, the server SHOULD reject the command with ERR_NEEDMOREPARAMS (even if an empty parameter is provided); otherwise it MUST use a default value instead.

The second and third parameters of this command SHOULD be sent as one zero ('0', 0x30) and one asterisk character ('*', 0x2A) by the client, as the meaning of these two parameters varies between different versions of the IRC protocol.

Clients SHOULD use the nickname as a fallback value for <username> and <realname> when they don’t have a meaningful value to use.

If a client tries to send the USER command after they have already completed registration with the server, the ERR_ALREADYREGISTERED reply should be sent and the attempt should fail.

If the client sends a USER command after the server has successfully received a username using the Ident Protocol, the <username> parameter from this command should be ignored in favour of the one received from the identity server.
*/

