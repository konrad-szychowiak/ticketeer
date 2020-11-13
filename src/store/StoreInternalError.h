//
// Created by konrad on 13.11.2020.
//

#ifndef TICKETEER_STOREINTERNALERROR_H
#define TICKETEER_STOREINTERNALERROR_H

#include <exception>
#include <string>

class StoreInternalError : public std::exception {
  std::string more;

public:
  explicit StoreInternalError(std::string details);
  [[nodiscard]] const char *what() const noexcept override;
};

#endif // TICKETEER_STOREINTERNALERROR_H
