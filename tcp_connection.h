//
// Created by Bruce Jia on 2022/6/20.
//

#ifndef YAFTPD_TCP_CONNECTION_H
#define YAFTPD_TCP_CONNECTION_H

#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class tcp_connection
        : public boost::enable_shared_from_this<tcp_connection>
{
public:
    typedef boost::shared_ptr<tcp_connection> pointer;

    static pointer create(boost::asio::io_context& io_context);
    tcp::socket& socket();

    void start();

private:
    tcp_connection(boost::asio::io_context& io_context);

    void handle_write(const boost::system::error_code& /*error*/,
                      size_t /*bytes_transferred*/);

    tcp::socket socket_;
    std::string message_;
};

#endif //YAFTPD_TCP_CONNECTION_H
