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
#include "log_msg_type.h"
#include "log_cformatted.h"

namespace scfd
{
namespace utils
{

class log_std_basic
{
public:
    using log_msg_type = utils::log_msg_type;

public:
    log_std_basic() : log_lev(1) {}

    void msg(const std::string &s, log_msg_type mt = log_msg_type::INFO, int _log_lev = 1)
    {
        if ((mt != log_msg_type::ERROR)&&(_log_lev > log_lev)) return;
        //TODO
        if ((mt == log_msg_type::INFO)||(mt == log_msg_type::INFO_ALL))
            printf("INFO:    %s\n", s.c_str());
        else if (mt == log_msg_type::WARNING)
            printf("WARNING: %s\n", s.c_str());
        else if (mt == log_msg_type::ERROR)
            printf("ERROR:   %s\n", s.c_str());
        else 
            throw std::logic_error("log_std_basic::log: wrong t_msg_type argument");
    }
    void set_verbosity(int _log_lev = 1) { log_lev = _log_lev; }

private:
    int     log_lev;
};

using log_std = log_cformatted<log_std_basic>;

}

}

#endif
