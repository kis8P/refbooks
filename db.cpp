#include <iostream>

#include "db.hpp"

DB::DB() {
  db_file_.open( DB_FILE_NAME.c_str(), std::ios_base::in | std::ios_base::out | std::ios_base::app );
  if ( !db_file_.is_open() ) {
    std::cerr << "ERROR: Can't open " + DB_FILE_NAME + "." << std::endl;
  }
}

DB::~DB() {
  db_file_.close();
}

const std::string DB::DB_FILE_NAME = "data_base.txt";
