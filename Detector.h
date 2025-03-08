// Detector.h
// Description: Header file for the Detector class, representing a particle detector.
// Student ID: [11069686]
// Date: [08/03/2025]
#ifndef DETECTOR_H
#define DETECTOR_H

#include "Lepton.h"
#include <string>
#include <iostream>

// Detector class represents a particle detector with properties such as detector type, status, and particle count.
// It includes methods to turn the detector on/off, detect particles, and print detector information.
class Detector
{
private:
  std::string detector_type;
  bool status;
  int particle_count;

public:
  // default constructor
  Detector();

  // parameterized constructor
  Detector(std::string type);

  // destructor
  ~Detector();

  // open the detector
  void turn_on();

  // close the detector
  void turn_off();

  // detect a particle
  int detect_particle(const Lepton &particle);

  // print detector information
  void printDetectorInfo() const;

  // get the number of particles detected
  int get_particle_count() const;
};

#endif