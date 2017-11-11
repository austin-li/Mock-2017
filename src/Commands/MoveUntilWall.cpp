#include "MoveUntilWall.h"

MoveUntilWall::MoveUntilWall(int _distance) :distanceToTravel(_distance), distanceCount(0), distance(999){
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(driveTrain);
}

// Called just before this Command runs the first time
void MoveUntilWall::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void MoveUntilWall::Execute() {
	driveTrain->tankDrive(0.3, 0.3);
	if (distanceCount < 10) {
		distances[distanceCount] = driveTrain->getUltra();
		distanceCount += 1;
	} else {
		distance = 0;
		for (int i = 0; i < distanceCount; i++) {
			distance += distances[i];
		}
		distanceCount = 0;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool MoveUntilWall::IsFinished() {
	return distance < distanceToTravel;
}

// Called once after isFinished returns true
void MoveUntilWall::End() {
	driveTrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveUntilWall::Interrupted() {
	driveTrain->Stop();
}
