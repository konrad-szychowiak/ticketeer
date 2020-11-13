//
// Created by konrad on 13.11.2020.
//

#include "StoreInternalError.h"
#include <utility>

StoreInternalError::StoreInternalError(std::string details)
    : more(std::move(details)) {}

const char *StoreInternalError::what() const noexcept {
  std::string msg = "An error occurred in the database. (" + more + ")";
  return msg.c_str();
}
