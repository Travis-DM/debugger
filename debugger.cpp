#include <Arduino.h>
#include "debugger.h"



int DEBUGGER::msg(const char *format,...)
{ 
    if(com_debug_EN)
    {
        switch (dPort)
        {
        case 1:
            SerialUSB.print(format);
            break;
        case 2:
            SerialUSB1.print(format);
            break;
        case 3:
            SerialUSB2.print(format);
            break;
        case 4:
            Serial1.print(format);
            break;
        case 5:
            Serial2.print(format);
            break;
        case 6:
            Serial3.print(format);
            break;
        case 7:
            Serial4.print(format);
            break;
        case 8:
            Serial5.print(format);
            break;
        case 9:
            Serial6.print(format);
            break;
        case 10:
            Serial7.print(format);
            break;
        case 11:
            Serial8.print(format);
            break;
        }
    }
    return 0;
}
int DEBUGGER::msg(uint8_t level, const char *format,...)
{
    if(level <= dbLevel)
    {
        msg(format);
    }
}
void DEBUGGER::db_ip_Config(_IP_Config_ ip_config)
{
    ip_debug_EN = true;

}
void DEBUGGER::db_com_Config(uint8_t port)
{
    com_debug_EN = true;
    dPort = port;
}

void DEBUGGER::setPort(uint8_t port)
{
    db_com_Config(port);
}

DEBUGGER::DEBUGGER()
{

}
/*
DEBUGGER::DEBUGGER(_IP_Config_ ip_config)
{
    db_ip_Config(ip_config);
}
DEBUGGER::DEBUGGER(int port, _IP_Config_ ip_config)
{
    db_com_Config(port);
    db_ip_Config(ip_config);
}*/
DEBUGGER::~DEBUGGER()
{
    
}