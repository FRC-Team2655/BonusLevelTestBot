#include "OI.hpp"

Joystick *OI::js0 = nullptr;
jshelper::AxisConfig OI::driveConfig = jshelper::createAxisConfig(0.1, 0, 0.5);
jshelper::AxisConfig OI::rotateConfig = jshelper::createAxisConfig(0.1);

void OI::initControlls(){
	js0 = new Joystick(0);
}
