#pragma once
#include <string>
#include <stdexcept>

class Resource {
   public:
    enum class Type {
        WOOD,
        BRICK,
        WHEAT,
        SHEEP,
        ROCK,
        NONE
    };
    Resource() = default;
    Resource(Type type) : type(type) {}

    std::string toEmoji() const {
        switch (type) {
            case Type::WOOD:
                return "🌲";
            case Type::BRICK:
                return "🧱";
            case Type::WHEAT:
                return "🌾";
            case Type::SHEEP:
                return "🐑";
            case Type::ROCK:
                return "⛰️";
            case Type::NONE:
                return "🏜️";
            default:
                throw std::invalid_argument("Invalid resource");
        }
    }

    constexpr operator Type() const { return type; }

    explicit operator bool() const = delete;

   private:
    Type type;
};