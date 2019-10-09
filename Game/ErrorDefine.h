#ifndef _ERROR_DEFINE_H_
#define _ERROR_DEFINE_H_

#include <cstdint>

namespace ErrorDefine {

    using ErrorCode = std::int64_t;

    const static ErrorCode ERROR_NONE = 0;

    enum ERROR_BASE
    {
        ERROR_INTERNAL = 0x1000,

    };

    enum INTERNAL_ERROR
    {
        GET_HANDLE_FAILED    = 0x0001 | ERROR_INTERNAL,
        GET_CONSOLE_FAILED   = 0x0002 | ERROR_INTERNAL,
        SET_CONSOLE_FAILED   = 0x0003 | ERROR_INTERNAL,
    };
}
#endif
