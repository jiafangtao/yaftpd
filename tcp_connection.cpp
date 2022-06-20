//
// Created by Bruce Jia on 2022/6/20.
//

#include "tcp_connection.h"
#include "utils.h"

tcp_connection::pointer tcp_connection::create(boost::asio::io_context& io_context)
    {
        return pointer(new tcp_connection(io_context));
    }

    tcp::socket& tcp_connection::socket()
    {
        return socket_;
    }

    void tcp_connection::start()
    {
        message_ = utils::make_daytime_string();

        boost::asio::async_write(socket_, boost::asio::buffer(message_),
                                 boost::bind(&tcp_connection::handle_write, shared_from_this(),
                                             boost::asio::placeholders::error,
                                             boost::asio::placeholders::bytes_transferred));
    }


tcp_connection::tcp_connection(boost::asio::io_context& io_context)
            : socket_(io_context)
    {
    }

    void tcp_connection::handle_write(const boost::system::error_code& /*error*/,
                      size_t /*bytes_transferred*/)
    {
    }
