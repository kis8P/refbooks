#ifndef DB_HPP
#define DB_HPP

#include <string>
#include <fstream>

class DB {
public:
    DB();
    ~DB();

private:
    static const std::string DB_FILE_NAME;

    std::fstream db_file_;
};

#endif	// DB_HPP
