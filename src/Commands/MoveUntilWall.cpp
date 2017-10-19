#include "MoveUntilWall.h"

MoveUntilWall::MoveUntilWall(int _distance) :distanceToTravel(_distance){
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(driveTrain);
}

// Called just before this Command runs the first time
void MoveUntilWall::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void MoveUntilWall::Execute() {
	driveTrain->setSpeed(0.4);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveUntilWall::IsFinished() {
	if (driveTrain->getUltra() < distanceToTravel) {
		return true;
	} else {
		return false;
	}
}

// Called once after isFinished returns true
void MoveUntilWall::End() {
	driveTrain->setSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveUntilWall::Interrupted() {

}
