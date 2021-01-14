#pragma once

#include <utility>
#include <string>

class OldAssignment 
{
    public:

        void set (const std::string& var)
        {
            name = var;
        }

        std::string get() const 
        {
            return name;
        }

    private:
        std::string name;
};

class NewAssignment 
{
    public:
        void set (std::string var)
        {
            name = std::move(var);
        }

        std::string get() const 
        {
            return name;
        }


    private:
        std::string name;
};

