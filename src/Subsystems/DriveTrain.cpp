#include "DriveTrain.h"
#include "../RobotMap.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain"), driveMotor(new Jaguar(MOTORPORT)), ultrasonicSensor(new Ultrasonic(ULTRASONIC_TRIGGER, ULTRASONIC_ECHO)) {
	ultrasonicSensor->SetAutomaticMode(true);
}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

double DriveTrain::getUltra() {
	return ultrasonicSensor->GetRangeInches();
}

void DriveTrain::setSpeed(double speed) {
	driveMotor->Set(speed);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
