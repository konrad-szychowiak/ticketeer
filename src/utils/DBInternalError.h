//
// Created by konrad on 13.11.2020.
//

#ifndef TICKETEER_DBINTERNALERROR_H
#define TICKETEER_DBINTERNALERROR_H

#include <exception>
#include <string>

class DBInternalError : public std::exception {
  std::string more;

public:
  explicit DBInternalError(std::string details);
  [[nodiscard]] const char *what() const noexcept override;
};

#endif // TICKETEER_DBINTERNALERROR_H
