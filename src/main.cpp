#include "./cli/cli.h"
#include "./lib/DataBase.h"
#include "./lib/tickets/MultiTicket.h"
#include "./lib/tickets/PlaneTicket.h"

using namespace cli;

int main(int argc, char **argv) {
  auto available = new DataBase<TicketBase>();
  auto reserved = new DataBase<TicketBase>();

  auto pt = new PlaneTicket("Chrzypsko", "Świebodzin", 90.78, 2);
  auto p2 = new PlaneTicket("Poznań", "Luboń", 0.12, 3);
  auto mu = new MultiTicket(4, 0);

  available->add(pt);
  available->add(p2);
  available->add(mu);

  mu = *mu + p2;
  mu->addReservation(pt);

  available->listAll();

  return 0;
}
