/*
 * BallPickup.h
 *
 *  Created on: Feb 17, 2017
 *      Author: Anish
 */

#ifndef SRC_SYSTEMS_BALLPICKUP_H_
#define SRC_SYSTEMS_BALLPICKUP_H_
#include "WPILib.h"
#include "CANTalon.h"
#include "teleop/controls/Deadband.h"
#include "util/DeviceIDs.h"
#include "systems/Constants.h"
using namespace frc;
class Ball_Pickup {
public:
	Ball_Pickup(XboxController* controller);
	virtual ~Ball_Pickup();
	CANTalon* outerRoller;
	CANTalon* innerRoller;
	XboxController* control;
	DoubleSolenoid* Ball_BackDoor;
	bool elevatorToggle = true;
	void TeleopBallLoop();
	void BallInput(double speed);
	void BallOutput(double speed);
	void RaiseElevator();
	void LowElevator();
	void TeleopBallLoopToggled();
	void DualControlTeleop();
};

#endif /* SRC_SYSTEMS_BALLPICKUP_H_ */
