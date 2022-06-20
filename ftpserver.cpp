//
// Created by Bruce Jia on 2022/6/20.
//

#include "ftpserver.h"
#include "tcp_connection.h"
#include <boost/bind/bind.hpp>

ftp_server::ftp_server(boost::asio::io_context& io_context)
    : io_context_(io_context),
      acceptor_(io_context, tcp::endpoint(tcp::v4(), 13))
{
    start_accept();
}

void ftp_server::start_accept()
{
    tcp_connection::pointer new_connection =
            tcp_connection::create(io_context_);

    acceptor_.async_accept(new_connection->socket(),
                           boost::bind(&ftp_server::handle_accept, this, new_connection,
                                       boost::asio::placeholders::error));
}

void ftp_server::handle_accept(tcp_connection::pointer new_connection,
                   const boost::system::error_code& error)
{
    if (!error)
    {
        new_connection->start();
    }

    start_accept();
}
