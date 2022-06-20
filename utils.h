//
// Created by Bruce Jia on 2022/6/20.
//

#ifndef YAFTPD_UTILS_H
#define YAFTPD_UTILS_H

#include <string>

class utils {

public:
    static std::string make_daytime_string()
    {
        using namespace std; // For time_t, time and ctime;
        time_t now = time(0);
        return ctime(&now);
    }

};


#endif //YAFTPD_UTILS_H
