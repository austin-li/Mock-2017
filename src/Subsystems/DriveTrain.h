#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>

#include "WPILib.h"

class DriveTrain : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Jaguar* driveMotor;
	Ultrasonic* ultrasonicSensor;

public:
	DriveTrain();
	void InitDefaultCommand();
	double getUltra();
};

#endif  // DriveTrain_H
