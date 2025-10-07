#pragma once
#include <string>


#ifdef LEAVERDLL_EXPORTS
#  define LEAVER_API __declspec(dllexport)
#else
#  define LEAVER_API __declspec(dllimport)
#endif

namespace leaverlib {

    class LEAVER_API Leaver {
    public:
        std::string leave(const std::string& name) const;
    };

} 