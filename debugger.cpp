#include <Arduino.h>
#include "debugger.h"


int DEBUG::msg(const char *format,...)
{ 
    if(com_debug_EN)
    {
        debug.printf(format);
    }
    return 0;
}

DEBUG::db_ip_Config(_IP_Config_ ip_config)
{
    ip_debug_EN = true;

}
DEBUG::db_com_Config(uint8_t port)
{
    com_debug_EN = true;
    switch (port)
    {
    case 1:
        HardwareSerial &debug SerialUSB
        break;
    case 2:
        HardwareSerial &debug SerialUSB1
        break;
    case 3:
        HardwareSerial &debug SerialUSB2
        break;
    case 4:
        HardwareSerial &debug Serial1
        break;
    case 5:
        HardwareSerial &debug Serial2
        break;
    case 6:
        HardwareSerial &debug Serial3
        break;
    case 7:
        HardwareSerial &debug Serial4
        break;
    case 8:
        HardwareSerial &debug Serial5
        break;
    case 9:
        HardwareSerial &debug Serial6
        break;
    case 10:
        HardwareSerial &debug Serial7
        break;
    case 11:
        HardwareSerial &debug Serial8
        break;
    
    default:
        com_debug_EN = false;
        break;
    }
}

DEBUG::DEBUG(int port)
{
    db_com_Config(port);
}

DEBUG::DEBUG(_IP_Config_ ip_config)
{
    db_ip_Config(ip_config);
}
DEBUG::DEBUG(int port, _IP_Config_ ip_config)
{
    db_com_Config(port);
    db_ip_Config(ip_config);
}
DEBUG::~DEBUG()
{
    
}