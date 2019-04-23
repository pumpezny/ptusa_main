/// @file profibus_slave_w750.h
/// @brief �������� �������� �������, ������� ��������� ���������� ����� PAC
/// �� ������ � Profibus Slave ��� PC.
///
/// @author  ������ ������� ���������.
///
/// @par �������� �������� �������������:
/// @c DEBUG    - ���������� c ������� ���������� ���������� � �������.@n@n
///
/// @par ������� ������:
/// @$Rev: 220 $.\n
/// @$Author: id $.\n
/// @$Date:: 2011-02-15 16:58:56#$.

#ifndef PROFIBUS_SLAVE_w750
#define PROFIBUS_SLAVE_w750

#include "profibus_slave.h"

//-----------------------------------------------------------------------------
/// @brief ������ � Profibus Slave.
class profibus_slave_w750 : public profibus_slave
    {
    public:
        int init()
            {
            return 0;
            }

        int eval()
            {
            return 0;
            }

        static profibus_slave* get_instance()
            {
            return instance;
            }

        virtual double get_double( int offset )
            {
            return 0;
            }

        virtual bool get_bool( int byte_offset, int bit_offset )
            {
           return false;
            }

        virtual void set_bool( int byte_offset, int bit_offset, bool val )
            {
            }

        virtual int get_int( int byte_offset )
            {
            return 0;
            }

        virtual void set_int( int byte_offset, int val )
            {
            }

        virtual int get_int4( int byte_offset )
            {
	    return 0;
	    }

    private:
        static profibus_slave_w750* instance;
    };
//-----------------------------------------------------------------------------

#endif // PROFIBUS_SLAVE
