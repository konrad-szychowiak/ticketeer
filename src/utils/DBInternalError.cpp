//
// Created by konrad on 13.11.2020.
//

#include "DBInternalError.h"
#include <utility>

DBInternalError::DBInternalError(std::string details)
    : more(std::move(details)) {}

const char *DBInternalError::what() const noexcept {
  std::string msg = "An error occurred in the database. (" + more + ")";
  return msg.c_str();
}
