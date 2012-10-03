#ifndef JSON_HPP_
#define JSON_HPP_

#include <string>

namespace Json {

enum class ValueType {
    STRING, NUMBER, OBJECT, ARRAY, BOOLEAN, NULL_VALUE
};

class Value {
public:
    Value() : type_( ValueType::NULL_VALUE ) {}
    Value( ValueType type ) : type_( type ) {}

    ValueType getType() const { return type_; }

protected:
    ValueType type_;
};

class String : public Value {
public:
    String( std::string str ) : Value( ValueType::STRING ),
                                data_( str ) {}

    std::string get() const { return data_; }

private:
    std::string data_;
};

class Number : public Value {
};

class Array : public Value {
};

class Boolean : public Value {
};

class Object : public Value {
};

} // namespace Json

#endif  // JSON_HPP_
