//
// Created by Bruce Jia on 2022/5/27.
//

#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>

#include "ftpserver.h"

using boost::asio::ip::tcp;


int main()
{
    try
    {
        std::cout << "starting server ..." << std::endl;
        boost::asio::io_context io_context;
        ftp_server server(io_context);
        io_context.run();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}