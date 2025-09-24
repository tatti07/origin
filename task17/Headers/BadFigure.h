#pragma once
#include <stdexcept>
#include <string>

class BadFigure : public std::domain_error {
public:
    explicit BadFigure(const std::string& message)
        : std::domain_error(message) {}
};