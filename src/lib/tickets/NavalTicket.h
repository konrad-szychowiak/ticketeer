//
// Created by konrad on 05.10.2020.
//

#ifndef NATIONALCPP_NAVALTICKET_H
#define NATIONALCPP_NAVALTICKET_H

#include "SingleTicket.h"

class NavalTicket : public SingleTicket {
private:
  typedef SingleTicket super;

public:
  static const char meta = 'n';

  NavalTicket(IDType id, Cost cost, std::string from, std::string to);

  string toString() override;
};

#endif // NATIONALCPP_NAVALTICKET_H
