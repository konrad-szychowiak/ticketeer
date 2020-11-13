cmake_minimum_required(VERSION 3.17)
project(ticketeer)

set(CMAKE_CXX_STANDARD 20)

add_executable(ticketeer src/main.cpp src/lib/TicketBase.cpp src/lib/TicketBase.h src/lib/PlaneTicket.cpp src/lib/PlaneTicket.h src/lib/NavalTicket.cpp src/lib/NavalTicket.h src/lib/MultiTicket.cpp src/lib/MultiTicket.h src/lib/TicketBase.cpp src/lib/TicketBase.h src/store/Store.h src/cli/cli.cpp src/cli/cli.h src/lib/SingleTicket.cpp src/lib/SingleTicket.h src/types/types.h src/store/utils.h src/store/utils.cpp src/store/StoreInternalError.cpp src/store/StoreInternalError.h)