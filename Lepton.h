// Lepton.h
// Description: Header file for the Lepton class, representing a lepton particle.
// Student ID: [11069686]
// Date: [08/03/2025]

#ifndef LEPTON_H
#define LEPTON_H

#include <string>
#include <iostream>
#include <vector>

// Lepton class represents a lepton particle with properties such as mass, charge, and velocity.
// It includes methods to set and get particle properties, as well as to print particle data.
class Lepton {
  private:
      std::string particle_type;
      double mass;
      int charge;
      double velocity;
      double beta;
      const double light_speed = 2.997458e8;
      std::vector<std::string> errors; // store error messages
  public:
      // Default constructor
      Lepton();
      // Parameterized constructor
      Lepton(std::string particle_type, double mass, int charge , double velocity); 
      // Destructor 
      ~Lepton();
      // Setters
      void set_particle_type(std::string particle_type);
      void set_mass(double mass);
      void set_charge(int charge);
      void set_velocity(double velocity);
      void set_beta(double beta);
      // Getters
      std::string get_particle_type() const;
      double get_mass() const;
      int get_charge() const;
      double get_velocity() const;
      double get_beta() const;
      // Member function to get errors
      std::vector<std::string> get_errors() const;
      // Member function to print out all particle data
      void print_particle_data() const;
  };
#endif