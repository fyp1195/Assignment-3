// Lepton.cpp
// Description: Implementation file for the Lepton class.
// Student ID: [11069686]
// Date: [08/03/2025]
#include "Lepton.h"
#include <iostream>

// default constructor
Lepton::Lepton() : particle_type("electron"), mass(0.511), charge(-1), velocity(0.0), beta(0.0)
{
  std::cout << "Default constructor called" << std::endl;
}

// parameterized constructor
Lepton::Lepton(std::string particle_type, double mass, int charge, double velocity)
    : particle_type(particle_type), mass(mass), charge(charge), velocity(velocity)
{
  // validate the particle
  if (particle_type != "electron" && particle_type != "muon")
  {
    errors.push_back("Warning: Invalid particle type: " + particle_type);
    this->particle_type = "Invalid Particle";
  }
  if (mass <= 0)
  {
    errors.push_back("Warning: Invalid mass, must be greater than 0. ");
    this->particle_type = "Invalid Particle";
  }
  if (charge != -1 && charge != 1)
  {
    errors.push_back("Warning: Invalid charge, must be -1 or 1. ");
    this->particle_type = "Invalid Particle";
  }
  if (velocity < 0 || velocity > light_speed)
  {
    errors.push_back("Warning: Invalid velocity, must be between 0 and the speed of light. ");
    this->particle_type = "Invalid Particle";
  }
  beta = velocity / light_speed;
}

// destructor
Lepton::~Lepton()
{
}

// Setters
void Lepton::set_particle_type(std::string particle_type)
{
  this->particle_type = particle_type;
}
void Lepton::set_mass(double mass)
{
  this->mass = mass;
}
void Lepton::set_charge(int charge)
{
  this->charge = charge;
}
void Lepton::set_velocity(double velocity)
{
  this->velocity = velocity;
  this->beta = velocity / light_speed;
}
void Lepton::set_beta(double beta)
{
  this->beta = beta;
  this->velocity = beta * light_speed;
}

// Getters
std::string Lepton::get_particle_type() const
{
  // if the particle is invalid, return "Invalid Particle"
  if (particle_type == "Invalid Particle")
  {
    return "Invalid Particle";
  }
  // if the particle is a charged lepton, return the corresponding antiparticle
  if (charge == 1)
  {
    if (particle_type == "electron")
    {
      return "positron"; // positron
    }
    else if (particle_type == "muon")
    {
      return "antimuon"; // antimuon
    }
  }
  return particle_type;
}
double Lepton::get_mass() const
{
  return mass;
}
int Lepton::get_charge() const
{
  return charge;
}
double Lepton::get_velocity() const
{
  return velocity;
}
double Lepton::get_beta() const
{
  return beta;
}

// Member function to get errors
std::vector<std::string> Lepton::get_errors() const
{
  return errors;
}

void Lepton::print_particle_data() const
{
  // if the particle is invalid, print the errors and return
  if (particle_type == "Invalid Particle")
  {
    std::cerr << "Error: Invalid particle info" << std::endl;
    for (const auto &error : errors)
    {
      std::cerr << " - " << error << std::endl;
    }
    return;
  }

  // print the particle data
  std::cout << "Particle type: " << get_particle_type() << std::endl;

  // print the mass, charge, velocity, and beta
  std::cout << "Mass: " << mass << " MeV" << std::endl;
  std::cout << "Charge: " << charge << " e" << std::endl;
  std::cout << "Velocity: " << velocity << " m/s" << std::endl;
  std::cout << "Beta: " << beta << std::endl;
}