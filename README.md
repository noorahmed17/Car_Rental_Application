Car Rental Console Application

A C++ Console-Based Car Rental System that allows customers to rent cars, managers to manage cars and reservations, and drivers to view assigned reservations. The application features secure authentication, role-based access, reservations, driver assignments, and a feedback system.

Features
Main Menu

Login: Secure authentication with username and password.

Register: Only available for new customers.

Exit: Close the application.

User Roles

Customers:

View available cars.

Reserve a car (with date selection and cost calculation).

Cancel reservations.

View personal reservations.

Managers (Admin-like functionality):

Manage cars (add, edit, remove).

View all reservations.

Assign drivers to reservations.

Manage user feedback.

Drivers:

View reservations assigned to them.

Car Management

Each car has:

ID, Model, Rental Cost, Availability

Status updates automatically (e.g., after reservation end dates).

Reservations

Auto-generated reservation IDs.

Cost calculation based on rental days.

Status updates for reservation creation or cancellation.

Driver Assignment

Assign available drivers to reservations.

Feedback System

Users (customers) can provide feedback on their experience.

Getting Started

Follow these steps to get the application running on your local machine.

Prerequisites

C++ Compiler (like g++) supporting C++17.

Visual Studio Code or any preferred IDE for running console applications.

Clone the Repository
git clone https://github.com/your-username/Car-Rental-System.git
cd Car-Rental-System

Compile the Code

Open a terminal in the project directory and run:

g++ -std=c++17 -static -g Car_Rental_System.cpp AuthService.cpp Customer.cpp CustomerService.cpp Manager.cpp File.cpp FileFunctions.cpp User.cpp Cars.cpp Driver.cpp Feedbacks.cpp Reservation.cpp -o SWE.exe


-std=c++17: Use C++17 standard.

-static: Produce a statically linked executable.

-g: Include debugging information.

-o SWE.exe: Name of the compiled executable.

Run the Application

In the terminal, run:

./SWE.exe      # On Linux/Mac
SWE.exe        # On Windows


The program will open the Main Menu with options to Login, Register, or Exit.

Follow the prompts based on your role (Customer, Manager, Driver).

Project Structure
File	Description
Car_Rental_System.cpp	Main entry point of the application
AuthService.cpp	Handles user authentication and registration
Customer.cpp	Customer class and related methods
CustomerService.cpp	Customer operations (reservations, view cars, etc.)
Manager.cpp	Manager operations (manage cars, assign drivers)
File.cpp	File handling for persistent data
FileFunctions.cpp	Helper functions for reading/writing files
User.cpp	Base user class (shared by Customer, Manager, Driver)
Cars.cpp	Car class and management logic
Driver.cpp	Driver class and assigned reservations
Feedbacks.cpp	Feedback system for customers
Reservation.cpp	Reservation creation, status, and cost calculation
Usage Example

Customer Flow:

Register → Login → View Cars → Reserve Car → View Reservations → Provide Feedback.

Manager Flow:

Login → Manage Cars → Assign Drivers → View Reservations → Manage Feedbacks.

Driver Flow:

Login → View Assigned Reservations.
