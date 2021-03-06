/*
 * DriveSystem.h
 *
 *  Created on: Feb 10, 2017
 *      Author: 4810
 */

#ifndef SRC_SYSTEMS_DRIVESYSTEM_DRIVESYSTEM_H_
#define SRC_SYSTEMS_DRIVESYSTEM_DRIVESYSTEM_H_

#include <CANTalon.h>
#include <RobotDrive.h>
#include <AnalogGyro.h>
#include <ADXRS450_Gyro.h>
#include <PWM.h>
#include <util/DeviceID.h>
#include <Timer.h>
#include <cmath>
#include <util/ConstantVals.h>
#include <SerialPort.h>
#include <PIDSource.h>
#include <PIDOutput.h>

using namespace frc;

class DriveSystem {

public:
	DriveSystem(RobotDrive* roboDrive, ADXRS450_Gyro* gyro);
	~DriveSystem();

	RobotDrive* drov;
	ADXRS450_Gyro* gyr;

	void TankControllerDrive(double leftSpeed, double rightSpeed);
	void ArcadeControllerDrive(double moveSpeed, double turnSpeed);
	void TimeStraightDrive(double driveSpeed, double driveSeconds);
	void TimeStraightGyroDrive(double driveSpeed, double driveSeconds);
	void TimeRotateDrive(double driveSpeed, double driveSeconds);
	double EncoderScale(int encoderReading, double wheelDiameterInches);
	void DistanceStraightDrive(double positiveDriveSpeed, double driveFeet);
	void RotateDrive(double positiveDriveSpeed, double driveDegrees, bool reInitializeGyro);
	void GearVisionDrive(double stopDist);

	//Gyro PID Variables
	double gyroIAccum = 0;

private:

protected:

};

#endif /* SRC_SYSTEMS_DRIVESYSTEM_DRIVESYSTEM_H_ */
