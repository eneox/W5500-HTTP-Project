#include "w5500_init.h"

#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include <stdarg.h>
#include <stdbool.h>
#include <ctype.h>

//#include "socket.h"
//#include "dhcp.h"
//#include "dns.h"
#include "httpServer.h"
#include "webpage.h"

#include "loopback.h"

//////////////////////////////////////////////////
// Socket & Port number definition for Examples //
//////////////////////////////////////////////////
#define SOCK_TCPS       0
#define SOCK_UDPS       1
#define PORT_TCPS		5000
#define PORT_UDPS       3000

#define MAX_HTTPSOCK	6


void Init_WebAPP (void);
void Task_WebAPP (void);
