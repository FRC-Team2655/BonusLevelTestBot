#pragma once

#include "team2655/joystick.hpp"

#include <Joystick.h>

using namespace team2655;
using namespace frc;

#define DriveAxis 1
#define RotateAxis 2
#define IntakeInButton 6
#define IntakeOutButton 5
#define IntakeUpButton 2
#define IntakeDownButton 3
#define IntakeOpenButton 8
#define ResetSensorButton 10

class OI{
public:
	static jshelper::AxisConfig driveConfig, rotateConfig;
	static Joystick *js0;

	static void initControlls();
};
