/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Subsystems/IntakeSubsystem.hpp>

#include "../RobotMap.hpp"
#include <ctre/Phoenix.h>
#include <DoubleSolenoid.h>

IntakeSubsystem::IntakeSubsystem() : Subsystem("IntakeSubsystem") {

}

void IntakeSubsystem::setIntakeSpeed(double speed){
	RobotMap::leftIntake->Set(ControlMode::PercentOutput, speed);
}
void IntakeSubsystem::setIntakeRaise(bool isRaised){
	RobotMap::intakeRaiseSolenoid->Set((isRaised) ? frc::DoubleSolenoid::Value::kForward : frc::DoubleSolenoid::Value::kReverse);
}
void IntakeSubsystem::setIntakeOpen(bool isOpen){
	RobotMap::intakeOpenSolenoid->Set((isOpen) ? frc::DoubleSolenoid::Value::kReverse : frc::DoubleSolenoid::Value::kForward);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
