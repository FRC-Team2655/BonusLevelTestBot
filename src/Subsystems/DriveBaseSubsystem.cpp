#include <Subsystems/DriveBaseSubsystem.hpp>
#include <SmartDashboard/SmartDashboard.h>
#include <iostream>
#include <Commands/Subsystem.h>
#include "../RobotMap.hpp"
#include <ctre/Phoenix.h>
#include "values.h"

/////////////////////////////////////////////////////////////////////
/// DriveBaseSubsystem
/////////////////////////////////////////////////////////////////////

DriveBaseSubsystem::DriveBaseSubsystem() : Subsystem("DriveBaseSubsystem"){

}

void DriveBaseSubsystem::drivePercentage(double speed, double rotation){
	std::array<double, 2> speeds = arcadeDrive(speed, rotation);
	SmartDashboard::PutNumber("LeftMotorOut", speeds[0]);
	SmartDashboard::PutNumber("RightMotorOutput", speeds[1]);
	RobotMap::left->Set(speeds[0]);
	RobotMap::right->Set(speeds[1]);
	RobotMap::pwmOther->Set(speeds[0]);
}

std::array<double, 2> DriveBaseSubsystem::arcadeDrive(double xSpeed, double zRotation) {
	double leftMotorOutput;
	double rightMotorOutput;

	// Prevent -0 from breaking the arcade drive...
	xSpeed += 0.0;
	zRotation += 0.0;

	double maxInput = std::copysign(std::max(std::abs(xSpeed), std::abs(zRotation)), xSpeed);

	if (xSpeed >= 0.0) {
		// First quadrant, else second quadrant
		if (zRotation >= 0.0) {
			leftMotorOutput = maxInput;
			rightMotorOutput = xSpeed - zRotation;
		} else {
			leftMotorOutput = xSpeed + zRotation;
			rightMotorOutput = maxInput;
		}
	} else {
		// Third quadrant, else fourth quadrant
		if (zRotation >= 0.0) {
			leftMotorOutput = xSpeed + zRotation;
			rightMotorOutput = maxInput;
		} else {
			leftMotorOutput = maxInput;
			rightMotorOutput = xSpeed - zRotation;
		}
	}

	return { leftMotorOutput, rightMotorOutput };
}
