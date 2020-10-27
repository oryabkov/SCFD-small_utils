// Copyright © 2016-2020 Ryabkov Oleg Igorevich, Evstigneev Nikolay Mikhaylovitch

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

#ifndef __SCFD_UTILS_LOG_CFORMATTED_BASE_H__
#define __SCFD_UTILS_LOG_CFORMATTED_BASE_H__

namespace scfd
{
namespace utils
{

/**
* LogBasic concept:
* class enum log_msg_type that contains at least INFO,INFO_ALL,WARNING,ERROR
* void msg(const std::string &s, log_msg_type mt = log_msg_type::INFO, int _log_lev = 1);
* lesser log level corresponds to more important messages
* void set_verbosity(int _log_lev = 1);
* set_verbosity sets maximum level of messages to log
* NOTE log_lev doesnot affects errors
*/ 

template<class LogBasic>
class log_cformatted : public LogBasic
{
public:
    using typename LogBasic::log_msg_type;
    using LogBasic::msg;
    using LogBasic::set_verbosity;

public:
    void info(const std::string &s, int _log_lev = 1)
    {
        msg(s, log_msg_type::INFO, _log_lev);
    }
    void info_all(const std::string &s, int _log_lev = 1)
    {
        msg(s, log_msg_type::INFO_ALL, _log_lev);
    }
    void warning(const std::string &s, int _log_lev = 1)
    {
        msg(s, log_msg_type::WARNING, _log_lev);
    }
    void error(const std::string &s, int _log_lev = 1)
    {
        msg(s, log_msg_type::ERROR, _log_lev);
    }   
    

    #define LOG__FORMATTED_OUT_V__(METHOD_NAME,LOG_LEV)   \
        vsprintf(buf, s.c_str(), arguments);              \
        METHOD_NAME(std::string(buf), LOG_LEV);
    void v_info_f(int _log_lev, const std::string &s, va_list arguments)
    {
        LOG__FORMATTED_OUT_V__(info, _log_lev)
    }
    void v_info_all_f(int _log_lev, const std::string &s, va_list arguments)
    {
        LOG__FORMATTED_OUT_V__(info_all, _log_lev)
    }
    void v_warning_f(int _log_lev, const std::string &s, va_list arguments)
    {
        LOG__FORMATTED_OUT_V__(warning, _log_lev)
    }
    void v_error_f(int _log_lev, const std::string &s, va_list arguments)
    {
        LOG__FORMATTED_OUT_V__(error, _log_lev)
    }
    void v_info_f(const std::string &s, va_list arguments)
    {
        LOG__FORMATTED_OUT_V__(info, 1)
    }
    void v_info_all_f(const std::string &s, va_list arguments)
    {
        LOG__FORMATTED_OUT_V__(info_all, 1)
    }
    void v_warning_f(const std::string &s, va_list arguments)
    {
        LOG__FORMATTED_OUT_V__(warning, 1)
    }
    void v_error_f(const std::string &s, va_list arguments)
    {
        LOG__FORMATTED_OUT_V__(error, 1)
    }
    #undef LOG__FORMATTED_OUT_V__ 


    #define LOG__FORMATTED_OUT__(METHOD_NAME,LOG_LEV)   \
        va_list arguments;                              \
        va_start ( arguments, s );                      \
        vsprintf(buf, s.c_str(), arguments);            \
        METHOD_NAME(std::string(buf), LOG_LEV);         \
        va_end ( arguments );   
    void info_f(int _log_lev, const std::string &s, ...)
    {
        LOG__FORMATTED_OUT__(info, _log_lev)
    }
    void info_all_f(int _log_lev, const std::string &s, ...)
    {
        LOG__FORMATTED_OUT__(info_all, _log_lev)
    }
    void warning_f(int _log_lev, const std::string &s, ...)
    {
        LOG__FORMATTED_OUT__(warning, _log_lev)
    }
    void error_f(int _log_lev, const std::string &s, ...)
    {
        LOG__FORMATTED_OUT__(error, _log_lev)
    }
    void info_f(const std::string &s, ...)
    {
        LOG__FORMATTED_OUT__(info, 1)
    }
    void info_all_f(const std::string &s, ...)
    {
        LOG__FORMATTED_OUT__(info_all, 1)
    }
    void warning_f(const std::string &s, ...)
    {
        LOG__FORMATTED_OUT__(warning, 1)
    }
    void error_f(const std::string &s, ...)
    {
        LOG__FORMATTED_OUT__(error, 1)
    }
    #undef LOG__FORMATTED_OUT__

private:
    char    buf[200];


};

}
}

#endif
