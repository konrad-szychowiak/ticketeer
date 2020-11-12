//
// Created by konrad on 05.10.2020.
//

#ifndef NATIONALCPP_TICKETBASE_H
#define NATIONALCPP_TICKETBASE_H

#include "../../utils/types.h"
#include <string>
#include <utility>

using namespace std;

class TicketBase {
private:
  IDType id;
  Cost cost;

public:
  TicketBase(IDType id, Cost cost);
  TicketBase() = default;

  // id
  IDType getId() const;

  // cost
  float getCost() const;
  void setCost(float value);
  string getPrintableCost(string &CURRENCY) const;

  virtual string toString();
};

#endif // NATIONALCPP_TICKETBASE_H
