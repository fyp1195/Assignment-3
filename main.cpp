// main.cpp
// Description: Main program to test the Lepton and Detector classes.
// Student ID: [11069686]
// Date: [08/03/2025]
#include "Lepton.h"
#include "Detector.h"
#include <vector>
#include <iostream>

// Main function to test the Lepton and Detector classes.
// Instantiates Lepton objects, detects particles using Detector objects, and prints results.
int main() {
    try {
        // Instantiate Lepton objects
        Lepton electron1("electro", 0.511, -1, 1.0e8); // invalid particle type
        Lepton electron2("electron", 0.511, -1, 3.5e8); // invalid velocity
        Lepton muon1("muon", -1, -1, 2.0e8); // invalid mass
        Lepton muon2("muon", 105.658, -2, 2.5e8); // invalid charge
        Lepton muon3("muon", 105.658, -1, 2.997458e8); // valid
        Lepton muon4("muon", 105.658, -1, 2.5e8); // valid
        Lepton positron("electron", 0.511, 1, 1.0e8); // valid
        Lepton antimuon("muon", 105.658, 1, 2.0e8); // valid

        // put them in a vector
        std::vector<Lepton> particles = {electron1, electron2, muon1, muon2, muon3, muon4, positron, antimuon};

        // print particle data
        std::cout << "===== Printing Particle Data =====" << std::endl;
        for (const auto& particle : particles) {
            particle.print_particle_data();
            std::cout << "------------------------------" << std::endl;
        }

        // Instantiate Detector objects
        Detector tracker("tracker");
        Detector calorimeter("calorimeter");
        Detector muonChamber("muon chamber");

        // open the detectors
        tracker.turn_on();
        calorimeter.turn_on();
        muonChamber.turn_on();

        // detect particles
        std::cout << "\n===== Detecting Particles =====" << std::endl;
        for (const auto& particle : particles) {
            tracker.detect_particle(particle);
            calorimeter.detect_particle(particle);
            muonChamber.detect_particle(particle);
            std::cout << "------------------------------" << std::endl;
        }

        // turn off the detectors
        tracker.turn_off();
        calorimeter.turn_off();
        muonChamber.turn_off();

        // print detector information
        std::cout << "\n===== Detector Information =====" << std::endl;
        tracker.printDetectorInfo();
        calorimeter.printDetectorInfo();
        muonChamber.printDetectorInfo();

        // test detecting particles when detectors are off
        std::cout << "\n===== Testing Detector When OFF =====" << std::endl;
        tracker.detect_particle(electron1); // try to detect a particle when detector is off
        calorimeter.detect_particle(muon1);
        muonChamber.detect_particle(antimuon);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}