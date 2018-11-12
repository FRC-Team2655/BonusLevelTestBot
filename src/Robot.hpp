#pragma once

#include <string>

#include <IterativeRobot.h>

#define GyroKey "Gyro X"

class Robot : public frc::IterativeRobot {
public:
	void RobotInit() override;
	void RobotPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;

private:
};
