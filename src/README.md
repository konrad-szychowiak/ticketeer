## Entrypoint
 
+ `src/main.cpp`

## `types/`

+ Primitive types aliases (`types.h`):
    + `IDType` is `int`
    + `Const` is `float`

## `lib/` (tickets)

+ _abstract_ `TicketBase`: shares `id: IDType` and `cost: Cost`
    + _abstract_ `SingleTicket`: shares `from` and `to`
        + `PlaneTicket`
        + `NavalTicket`
    + `MultiTicket`: can hold multiple (0+) of all the above; **cannot** hold other `MultiTicket`s. 
 
 ## `store/` (_backend_)
 
 + `class Store<T>`: stores pointers to tickets fo type `T`
 + `StoreInternalError`: for errors, whilst using stored data
 + `utils.(h|cpp)`: collection of functions for handling communication between application's `Store`s and CSV files.
 
 ## `cli/` (_user interface_)
 Collection of functions for handling user-application communications.
 