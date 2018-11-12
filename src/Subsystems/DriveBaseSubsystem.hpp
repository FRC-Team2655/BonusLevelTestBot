#pragma once

#include <Commands/Subsystem.h>

class DriveBaseSubsystem : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::array<double, 2> arcadeDrive(double xSpeed, double zRotation);

public:
	DriveBaseSubsystem();
	void drivePercentage(double speed, double rotation);
};
