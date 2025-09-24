#pragma once
#include <string>
#include <iostream>

class Figure {
protected:
    std::string name;
    int sides_count;

public:
    Figure(std::string n = "Фигура", int sc = 0);
    virtual ~Figure() = default;

    const std::string& get_name() const;
    virtual bool check() const;
    virtual void print_info() const;
};