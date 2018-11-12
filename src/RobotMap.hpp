#pragma once

#include <ctre/Phoenix.h>
#include <Spark.h>
#include <Talon.h>
#include <SpeedControllerGroup.h>
#include <Compressor.h>
#include <DoubleSolenoid.h>
#include "adis/ADIS16448_IMU.h"

#include "Subsystems/DriveBaseSubsystem.hpp"
#include "Subsystems/IntakeSubsystem.hpp"

using namespace frc;

class RobotMap{
public:
	static Spark *leftOne, *leftTwo, *rightOne, *rightTwo;
	static Spark *pwmOther;
	// static Talon *pwmOther;
	static SpeedControllerGroup *left, *right;
	static WPI_TalonSRX *leftIntake, *rightIntake;
	static frc::Compressor *compressor;

	static frc::DoubleSolenoid *intakeOpenSolenoid;
	static frc::DoubleSolenoid *intakeRaiseSolenoid;

	static ADIS16448_IMU *imu;

	static void initHardware();
	static double getIMUAngle();

	static DriveBaseSubsystem *driveBase;
	static IntakeSubsystem *intake;
};
