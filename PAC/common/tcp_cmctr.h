/// @file tcp_cmctr.h
/// @brief �������� �������� �������, ������� ������������� ��� ������ �������
/// PAC-������ �� ��������� TCP.
/// 
/// @author  ������ ������� ���������.
///
/// @par �������� �������� �������������:
/// 
/// @par ������� ������:
/// @$Rev: 39 $.\n
/// @$Author: id@BMK $.\n
/// @$Date:: 2010-04-02 17:22:01#$.

#ifndef TCP_CMCTR_H
#define TCP_CMCTR_H

#include "sys.h"

//-----------------------------------------------------------------------------
/// @brief ������� ����� ������������ - ����� ������� PAC-������.
class tcp_communicator
    {
    public:
        /// @brief ����������� ������� �������.
        typedef long int srv_proc( long int, u_char *, u_char * );
        typedef srv_proc *srv_ptr;

        /// @brief ��������� ������������� ���������� ������ ��� ������ � 
        /// ��������������.
        ///
        /// @return - ��������� �� ������������ ������ ������ @ref
        /// tcp_communicator.
        static tcp_communicator* get_instance();

        /// @brief ������������� ������������� ���������� ������ ��� ������ � 
        /// ��������������.
        ///
        /// @param - ��������� �� ������������ ������ ������, ������������ ��
        /// @ref tcp_communicator.
        static void set_instance( tcp_communicator* new_instance );

        /// @brief �������� ������ ������� � ��������.
        virtual int evaluate() = 0;

        /// @brief ���������� ���������������� ������� �� ������ ������� - 
        /// �������.
        ///
        /// @param srv_id - �����, �� ������� ����� ��������� ������.
        /// @param fk     - ��������� �� ������ ����������� ����� ������.        
        srv_ptr reg_service( u_char srv_id, srv_ptr fk );

        /// @brief ��������� �������� ����� PAC.
        ///
        /// @return - ������� ��� PAC.
        char* get_host_name();

    protected:
        tcp_communicator();

        //ERRORS DEFINITION
        enum ERRORS
            {
            ERR_RETRIVE       = 1,
            ERR_WRONG_SERVICE = 3,
            ERR_TRANSMIT      = 4,
            ERR_WRONG_CMD     = 5,
            };

        //COMMANDS DEFINITION  
        enum COMMANDS 
            {
            FRAME_SINGLE = 1,
            AKN_ERR      = 7,
            AKN_DATA     = 8,
            AKN_OK       = 12,
            };

        enum CONSTANTS
            {
            BUFSIZE     = 16384,           ///< ������ ������.
            PORT 	= 10000,           ///< ����.
            MAX_SOCKETS = 32,              ///< ������������ ���������� �������.
            QLEN        = MAX_SOCKETS - 1, ///< ������������ ���������� ����������.

            TC_MAX_HOST_NAME      = 20,
            TC_MAX_SERVICE_NUMBER = 16,

            };

        static tcp_communicator* instance;          ///< ��������� ������.
        
        srv_ptr services[ TC_MAX_SERVICE_NUMBER ];  ///< ������ ��������.
        char    host_name[ TC_MAX_HOST_NAME ];      ///< ������� ��� PAC.

        int max_cycles;         ///< ������������ ���������� ������ ��������� ��������� ������� �� 1 ������.
        int is_going_to_reboot; ///< ���� ������������ PAC.
        int glob_cmctr_ok;      ///< ���� ���������� ������ � ��������.

        u_int   in_buffer_count;///< ���������� ������ � ������.
        u_char* buf;            ///< �����.

        u_char pidx;            ///< ����� ������.
        int    net_id;          ///< ����� PAC.

        void _ErrorAkn( u_char error );
        void _AknData( u_long len );
        void _AknOK();
    };
//-----------------------------------------------------------------------------
#endif //TCP_CMCTR_H