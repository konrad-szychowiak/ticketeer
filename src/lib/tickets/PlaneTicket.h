//
// Created by konrad on 05.10.2020.
//

#ifndef NATIONALCPP_PLANETICKET_H
#define NATIONALCPP_PLANETICKET_H

#include "SingleTicket.h"
#include <string>
#include <utility>

using namespace std;

class PlaneTicket : public SingleTicket {
  typedef SingleTicket super;

public:
  /**
   * p for *P*laneTicket
   * for csv serialisation
   */
  static const char meta = 'p';

  PlaneTicket(IDType id, Cost cost, std::string from, std::string to);

  string toString() override;
};

#endif // NATIONALCPP_PLANETICKET_H
