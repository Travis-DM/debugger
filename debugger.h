#ifndef _DEBUGGER_H_
#define _DEBUGGER_H_

#include <Arduino.h>

enum debug_levels
{
    silent = 0,
    quiet  = 1,
    normal = 2,
    verbos = 3
};

struct _IP_Address_
{
    uint8_t oct1;
    uint8_t oct2;
    uint8_t oct3;
    uint8_t oct4;
};

struct _IP_Config_
{
    _IP_Address_ ip_address;
    _IP_Address_ gateway;
    _IP_Address_ dns;
    _IP_Address_ netmask;
    uint16_t     port;
};


class DEBUGGER
{
private:
    uint8_t dbLevel = 3;
    uint8_t dPort;
    bool ip_debug_EN = false;
    bool com_debug_EN = false;
    void db_ip_Config(_IP_Config_ ip_config);
    void db_com_Config(uint8_t port);
public:
    int msg(const char *format,...);
    int msg(uint8_t level, const char *format,...);
    void setPort(uint8_t port);
    DEBUGGER();
    //DEBUGGER(_IP_Config_ ip_config);
    //DEBUGGER(int port, _IP_Config_ ip_config);

    ~DEBUGGER();
};

extern DEBUGGER debugger; 

#endif
