#include "Leaver.h"
#include <string>


using namespace leaverlib;

std::string Leaver::leave(const std::string& name) const {
    return "Goodbye, " + name + "!";
}