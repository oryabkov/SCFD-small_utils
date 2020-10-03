// Copyright © 2016-2018 Ryabkov Oleg Igorevich, Evstigneev Nikolay Mikhaylovitch

// This file is part of SCFD.

// SCFD is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 2 only of the License.

// SCFD is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with SCFD.  If not, see <http://www.gnu.org/licenses/>.

#ifndef __SCFD_UTILS_LOG_STD_H__
#define __SCFD_UTILS_LOG_STD_H__

#include <string>
#include <exception>
#include <stdexcept>
#include <cstdarg>
#include <cstdio>
#include "log_formatted_base.h"

namespace scfd
{
namespace utils
{

class log_std : public log_formatted_base<log_std>
{
    int     log_lev;
public:
    log_std() : log_lev(1) {}

    virtual void msg(const std::string &s, t_msg_type mt = INFO, int _log_lev = 1)
    {
        if ((mt != ERROR)&&(_log_lev > log_lev)) return;
        //TODO
        if ((mt == INFO)||(mt == INFO_ALL))
            printf("INFO:    %s\n", s.c_str());
        else if (mt == WARNING)
            printf("WARNING: %s\n", s.c_str());
        else if (mt == ERROR)
            printf("ERROR:   %s\n", s.c_str());
        else 
            throw std::logic_error("log_std::log: wrong t_msg_type argument");
    }
    virtual void set_verbosity(int _log_lev = 1) { log_lev = _log_lev; }
};

}

}

#endif
