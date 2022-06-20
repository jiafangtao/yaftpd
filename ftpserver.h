//
// Created by Bruce Jia on 2022/6/20.
//

#ifndef YAFTPD_FTP_SERVER_H
#define YAFTPD_FTP_SERVER_H

#include <boost/asio.hpp>
#include "tcp_connection.h"

using boost::asio::ip::tcp;

class ftp_server
{
public:
    ftp_server(boost::asio::io_context& io_context);

private:
    void start_accept();

    void handle_accept(tcp_connection::pointer new_connection,
                       const boost::system::error_code& error);

    boost::asio::io_context& io_context_;
    tcp::acceptor acceptor_;
};

#endif //YAFTPD_FTP_SERVER_H
