/*
 * Auto.h
 *
 *  Created on: Feb 21, 2017
 *      Author: 4810
 */

#ifndef SRC_AUTO_AUTO_H_
#define SRC_AUTO_AUTO_H_

#include <systems/DriveSystem/DriveSystem.h>
#include <systems/GearSystem/GearSystem.h>
#include <systems/ShootSystem/ShootSystem.h>
#include <DigitalInput.h>
#include <SerialPort.h>

class Auto {

public:
	Auto(DriveSystem* driveSystem, GearSystem* gearSystem, DigitalInput* gearDetectSensor,
			DigitalInput* pegDetectSensor1, ShootSystem* shootSystem);
	~Auto();

	void AutoInitialize(int position = 2);
	void AutonRun(bool gear, bool ball, bool sensor);

private:
	DriveSystem* drv;
	GearSystem* gr;
	DigitalInput* gDetect;
	DigitalInput* pDetect1;
	ShootSystem* sht;
	SerialPort* duino;

	bool ingear = false;
	bool ballDone = false;
	bool backedup = false;
	char *buff;
	int buffread1;
	int buffread2;
	int buffread3;

protected:

};

#endif /* SRC_AUTO_AUTO_H_ */
