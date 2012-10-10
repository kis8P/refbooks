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
    explicit Value( ValueType type ) : type_( type ) {}

    ValueType getType() const { return type_; }

protected:
    ValueType type_;
};

class String : public Value {
public:
    explicit String( std::string str ) : Value( ValueType::STRING ),
                                         data_( str ) {}

    std::string get() const { return data_; }

private:
    std::string data_;
};

class Number : public Value {
public:
    explicit Number( long n ) : Value( ValueType::NUMBER ),
                                data_( n ) {}

    long get() const { return data_; }

private:
    long data_;
};

class Array : public Value {
public:
    Array() : Value( ValueType::ARRAY ) {}

private:
    std::vector< Value > data_;
};

class Boolean : public Value {
};

class Object : public Value {
public:
    struct Pair {
        String name;
        Value *value;

        Pair( String n, Value *v ) : name( n ), value( v ) {}
    };

    Object() : Value( ValueType::OBJECT ) {}

    void add( String name, Value *value ) {
        data_.push_back( Pair( name, value ) );
    }

private:
    std::vector< Pair > data_;
};

// Parser


} // namespace Json

#endif  // JSON_HPP_
