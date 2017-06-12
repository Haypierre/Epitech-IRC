/*
** protocol.h for irc in /home/rutiyu/Epitech_second_year/unix_system/PSU_2016_myirc/common/include
**
** Made by Pierre Hay
** Login   <rutiyu@epitech.net>
**
** Started on  Thu May 25 12:24:03 2017 Pierre Hay
** Last update Sun Jun 11 22:19:45 2017 Pierre Hay
*/

#ifndef PROTOCOL_H_
# define PROTOCOL_H_

# define MAX_LEN_NICKNAME 9
# define MAX_LEN_CHANNEL 100
# define MAX_CHANNELS 10
# define REPLIESIZE 1024

# define ERR_UNKNOWNCMD "421 %s :Unknown command\r\n"
# define ERR_NEEDMOREPARAMS "461 %s %s :Not enough parameters\r\n"
# define ERR_NICKNAMEINUSE "433 %s :Nickname is already in use\r\n"
# define ERR_ERRONEUSNICKNAME "432 %s :Erroneus nickname\r\n"
# define ERR_NOSUCHNICK "401 %s :No such nick\r\n"
# define ERR_NONICKNAMEGIVEN "431 %s :No nickname given\r\n"
# define ERR_NOSUCHCHANNEL "403 %s %s :No such channel\r\n"
# define ERR_USERONCHANNEL "443 %s %s :is already on channel\r\n"
# define ERR_TOOMANYCHANNELS "405 %s :maximum number of channels reach\r\n"
# define ERR_NOTONCHANNEL "442 %s %s :You're not on that channel\r\n"
# define ERR_NORECIPIENT "411 %s :No recipient given (PRIVMSG)\r\n"
# define ERR_NOTEXTTOSEND "412 %s :No text to send\r\n"
# define ERR_CANNOTSENDTOCHAN "404 %s %s :Cannot send to channel\r\n"
# define ERR_ALREADYREGISTERED "462 :You may not reregister\r\n"
# define ERR_UNAVAILRESOURCE "437 %s :Nick/chan is temporarily unavailable\r\n"
# define RPL_AUTHENTIFIED "001 %s :Welcome in the QLF IRC world!\r\n"
# define RPL_NICKOK "NICK %s\r\n"
# define RPL_NICKOKPROP ":User NICK %s\r\n"
# define RPL_JOINOK ":%s JOIN :%s\r\n"
# define RPL_PARTOK ":%s PART :%s\r\n"
# define RPL_MSG " MSG "
# define RPL_PRIVMSG " PRIVMSG "
# define RPL_LISTSTART "321 Channel :Users Name\r\n"
# define RPL_LIST "322 "
# define RPL_LISTEND "323 :End of channel list\r\n"
# define RPL_USERSTART "392 :Users listing started\r\n"
# define RPL_USERS "393 : %s\r\n"
# define RPL_ENDOFUSERS "394 :End of users\r\n"
# define RPL_NOUSERS "395 :Nobody logged in\r\n"
# define RPL_NAMREPLY "353 %s :%s\r\n"
# define RPL_ENDOFNAMES "366 %s %s :End of /NAMES list\r\n"
# define RPL_OVERFLOW "421 Message too long\r\n"
# define ERR_NOTREGISTERED "451 %s :Register first\r\n"

#endif /* !PROTOCOL_H_ */
