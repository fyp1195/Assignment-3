// Detector.cpp
// Description: Implementation file for the Detector class.
// Student ID: [11069686]
// Date: [08/03/2025]
#include "Detector.h"

// default constructor
Detector::Detector() : detector_type("tracker"), status(false), particle_count(0)
{
}

// parameterized constructor
Detector::Detector(std::string type) : detector_type(type), status(false), particle_count(0)
{
	if (type != "tracker" && type != "calorimeter" && type != "muon chamber")
	{
		throw std::invalid_argument("Invalid detector type. Must be tracker, calorimeter, or muon chamber.");
	}
}

// destructor
Detector::~Detector()
{
}

// open the detector
void Detector::turn_on()
{
	status = true;
	std::cout << detector_type << " detector is now ON." << std::endl;
}

// close the detector
void Detector::turn_off()
{
	status = false;
	std::cout << detector_type << " detector is now OFF." << std::endl;
}
// detect a particle
int Detector::detect_particle(const Lepton &particle) {
	if (!status) {
			std::cout << "Detector is OFF. No particles detected." << std::endl;
			return 0;
	}

	// check if the particle is invalid
	if (particle.get_particle_type() == "Invalid Particle") {
			std::cout << "Invalid particle detected. Skipping detection." << std::endl;
			return 0;
	}

	std::string type = particle.get_particle_type();
	bool is_detected = false;

	// check if the particle is detected by the detector
	if (detector_type == "tracker" && (type == "electron" || type == "muon" || type == "positron" || type == "antimuon")) {
			is_detected = true;
	} else if (detector_type == "calorimeter" && (type == "electron" || type == "positron")) {
			is_detected = true;
	} else if (detector_type == "muon chamber" && (type == "muon" || type == "antimuon")) {
			is_detected = true;
	}

	// if the particle is detected, increment the particle count
	if (is_detected) {
			particle_count++;
			std::cout << type << " was detected by " << detector_type << "." << std::endl;
			return 1;
	} else {
			std::cout << type << " was NOT detected by " << detector_type << "." << std::endl;
			return 0;
	}
}

// print detector information
void Detector::printDetectorInfo() const
{
	std::cout << "Detector Type: " << detector_type << std::endl;
	std::cout << "Status: " << (status ? "ON" : "OFF") << std::endl;
	std::cout << "Particles Detected: " << particle_count << std::endl;
}

// get the number of particles detected
int Detector::get_particle_count() const
{
	return particle_count;
}