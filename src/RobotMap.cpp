#include "RobotMap.hpp"

Spark *RobotMap::leftOne = nullptr;
Spark *RobotMap::leftTwo = nullptr;
Spark *RobotMap::rightOne = nullptr;
Spark *RobotMap::rightTwo = nullptr;
SpeedControllerGroup *RobotMap::left = nullptr;
SpeedControllerGroup *RobotMap::right = nullptr;
WPI_TalonSRX *RobotMap::leftIntake = nullptr, *RobotMap::rightIntake = nullptr;
frc::Compressor *RobotMap::compressor = nullptr;
frc::DoubleSolenoid *RobotMap::intakeOpenSolenoid = nullptr;
frc::DoubleSolenoid *RobotMap::intakeRaiseSolenoid = nullptr;
ADIS16448_IMU *RobotMap::imu = nullptr;
DriveBaseSubsystem *RobotMap::driveBase = nullptr;
IntakeSubsystem *RobotMap::intake = nullptr;

void RobotMap::initHardware(){

	leftOne = new Spark(0);
	leftTwo = new Spark(1);
	rightOne = new Spark(2);
	rightTwo = new Spark(3);
	left = new SpeedControllerGroup(*leftOne, *leftTwo);
	right = new SpeedControllerGroup(*rightOne, *rightTwo);
	leftIntake = new WPI_TalonSRX(7);
	rightIntake = new WPI_TalonSRX(8);

	compressor = new frc::Compressor();

	intakeOpenSolenoid = new frc::DoubleSolenoid(0, 1);
	intakeRaiseSolenoid = new frc::DoubleSolenoid(2, 3);

	imu = new ADIS16448_IMU();

	driveBase = new DriveBaseSubsystem();
	intake = new IntakeSubsystem();
}

double RobotMap::getIMUAngle(){
	return imu->GetAngleX();
}
