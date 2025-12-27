#ifndef FILEFUNCTIONS_H
#define FILEFUNCTIONS_H

#include <vector>
#include "Car.h"
#include "Reservation.h"

// Cars
vector<Car> loadCars();
void saveCars(const vector<Car>& cars);

// Reservations
vector<Reservation> loadReservations();
void saveReservation(const Reservation& r);
void updateReservation(const Reservation& updatedRes);

#endif
