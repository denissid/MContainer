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

class MoveAssignment 
{
    public:
        void set (std::string var) noexcept
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

class ForwardAssignment 
{
    public:
        template <class T>
        void set (T&& t)
        {
            name = std::forward <T> (t);
        }

    private:
        std::string name;
};

