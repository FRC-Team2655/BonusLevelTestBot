#include <Robot.hpp>

#include <SmartDashboard/SmartDashboard.h>
#include <LiveWindow/LiveWindow.h>
#include <Joystick.h>

#include "RobotMap.hpp"
#include "OI.hpp"

void Robot::RobotInit(){
	RobotMap::initHardware();
	OI::initControlls();

	RobotMap::rightIntake->Follow(*RobotMap::leftIntake);
	RobotMap::imu->Reset();

	//RobotMap::right->SetInverted(true);

	// Don't let LiveWindow control SRX motor controllers or Test mode will break follower mode
	LiveWindow::GetInstance()->Remove(RobotMap::leftIntake);
	LiveWindow::GetInstance()->Remove(RobotMap::rightIntake);
}

void Robot::RobotPeriodic(){
	SmartDashboard::PutNumber(GyroKey, RobotMap::getIMUAngle());
}

void Robot::TeleopInit(){
	RobotMap::leftIntake->SetNeutralMode(NeutralMode::Coast);
	RobotMap::rightIntake->SetNeutralMode(NeutralMode::Coast);

	RobotMap::compressor->SetClosedLoopControl(false);
	RobotMap::compressor->SetClosedLoopControl(true);
}

void Robot::TeleopPeriodic(){
	//////////////////////////////////////////////////////////
	/// Intake
	//////////////////////////////////////////////////////////
	bool intakeIn = OI::js0->GetRawButton(IntakeInButton);
	bool intakeOut = OI::js0->GetRawButton(IntakeOutButton);
	bool intakeUp = OI::js0->GetRawButton(IntakeUpButton);
	bool intakeDown = OI::js0->GetRawButton(IntakeDownButton);
	bool intakeOpen = OI::js0->GetRawButton(IntakeOpenButton);

	if (intakeIn && !intakeOut) {
		RobotMap::intake->setIntakeSpeed(1);
	}else if (!intakeIn && intakeOut) {
		RobotMap::intake->setIntakeSpeed(-0.8);
	}else{
		RobotMap::intake->setIntakeSpeed(0);
	}

	RobotMap::intake->setIntakeOpen(intakeOpen);

	if (intakeUp && !intakeDown) {
		RobotMap::intake->setIntakeRaise(true);
	}else if (!intakeUp && intakeDown) {
		RobotMap::intake->setIntakeRaise(false);
	}

	///////////////////////////////////////////////////////////
	/// Drive
	///////////////////////////////////////////////////////////
	double power = -1 * jshelper::getAxisValue(OI::driveConfig, OI::js0->GetRawAxis(DriveAxis));
	double rotate = 0.5 * jshelper::getAxisValue(OI::rotateConfig, OI::js0->GetRawAxis(RotateAxis));
	RobotMap::driveBase->drivePercentage(power, rotate);
}

START_ROBOT_CLASS(Robot)
