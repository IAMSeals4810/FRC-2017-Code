#include <systems/DriveSystem/DriveSystem.h>

DriveSystem::DriveSystem(RobotDrive* roboDrive, ADXRS450_Gyro* gyro){
	drov = roboDrive;
	drov->SetSafetyEnabled(true);
	drov->SetExpiration(0.1);
	gyr = gyro;
}

DriveSystem::~DriveSystem(){

}

void DriveSystem::TankControllerDrive(double leftSpeed, double rightSpeed){
	drov->SetSafetyEnabled(true);
	drov->SetExpiration(0.1);
	drov->TankDrive(leftSpeed, rightSpeed, false);
}

void DriveSystem::ArcadeControllerDrive(double moveSpeed, double turnSpeed){
	drov->SetSafetyEnabled(true);
	drov->SetExpiration(0.1);
	drov->ArcadeDrive(moveSpeed, turnSpeed, false);
}

void DriveSystem::TimeStraightDrive(double driveSpeed, double driveSeconds){
	drov->SetSafetyEnabled(false);
	for(int i = 0; i <= driveSeconds*100; i++){
		drov->ArcadeDrive(driveSpeed, 0.0, false);
		Wait(0.01);
	}
	drov->ArcadeDrive(0.0, 0.0, false);
	drov->SetSafetyEnabled(true);
}

void DriveSystem::TimeStraightGyroDrive(double driveSpeed, double driveSeconds){
	drov->SetSafetyEnabled(false);
	gyr->Reset();
	gyroIAccum = 0.0; //Clearing I factor accumulation for gyro PID
	for(int i = 0; i <= driveSeconds*100; i++){
		gyroIAccum += gyr->GetAngle();
		double anglePCorrect = (gyr->GetAngle()*0.03);
		double angleICorrect = (gyroIAccum*0.0013);
		double angleCorrection = (anglePCorrect+angleICorrect);
		SmartDashboard::PutNumber("P", anglePCorrect);
		SmartDashboard::PutNumber("I", angleICorrect);
		SmartDashboard::PutNumber("Correction", angleCorrection);
		drov->ArcadeDrive(driveSpeed, angleCorrection, true);
		Wait(0.01);
	}
	drov->ArcadeDrive(0.0, 0.0, false);
	drov->SetSafetyEnabled(true);
}

void DriveSystem::TimeRotateDrive(double driveSpeed, double driveSeconds){
	drov->SetSafetyEnabled(false);
	for(int i = 0; i <= driveSeconds*100; i++){
		drov->ArcadeDrive(0.0, driveSpeed, false);
		Wait(0.01);
	}
	drov->ArcadeDrive(0.0, 0.0, false);
}

double DriveSystem::EncoderScale(int encoderReading, double wheelDiameterInches){
	double wheelIncrement = encoderReading/encoderRotationCounts;
	double wheelCircumference = M_PI*wheelDiameterInches;
	return wheelIncrement*wheelCircumference;
}

/*void DriveSystem::DistanceStraightDrive(double positiveDriveSpeed, double driveFeet){
	drov->SetSafetyEnabled(false);
	double travelDist = 0;
	double rotations = 0;
	if(driveFeet > 0){
		positiveDriveSpeed = abs(positiveDriveSpeed);
		int initRead = encoderRotationCounts - flE->GetRaw();
		while(travelDist < driveFeet){
			travelDist = EncoderScale(((rotations * encoderRotationCounts) + flE->GetRaw() + initRead), wheelDiameter);
			double dPower = positiveDriveSpeed * ((driveFeet-travelDist)/driveFeet);
			drov->ArcadeDrive(dPower, 0, false);
			if(flE->GetRaw()==0){
				rotations++;
			}
		}
	}
	else{
		positiveDriveSpeed = -abs(positiveDriveSpeed);
		int initRead = flE->GetRaw();
		while(travelDist > driveFeet){
			travelDist = -EncoderScale(((rotations * encoderRotationCounts) + (encoderRotationCounts - flE->GetRaw()) + initRead), wheelDiameter);
			double dPower = positiveDriveSpeed * ((driveFeet-travelDist)/driveFeet);
			drov->ArcadeDrive(dPower, 0, false);
			if(flE->GetRaw()==0){
				rotations++;
			}
		}
	}
	drov->ArcadeDrive(0.0, 0.0, false);
}

void DriveSystem::RotateDrive(double positiveDriveSpeed, double driveDegrees, bool reInitializeGyro){
	drov->SetSafetyEnabled(false);
	if(reInitializeGyro == true){
		gyr->Reset();
		if(driveDegrees > 0){
			positiveDriveSpeed = abs(positiveDriveSpeed);
			while(gyr->GetAngle() <= driveDegrees){
				double dPow = positiveDriveSpeed*((driveDegrees-(gyr->GetAngle()))/driveDegrees);
				drov->ArcadeDrive(0.0, dPow, false);
			}
		}
		else{
			positiveDriveSpeed = -abs(positiveDriveSpeed);
			while(gyr->GetAngle() >= driveDegrees){
				double dPow = positiveDriveSpeed*((driveDegrees-(gyr->GetAngle()))/driveDegrees);
				drov->ArcadeDrive(0.0, dPow, false);
			}
		}
	}
	else{
		double startAngle = gyr->GetAngle();
		double targetAngle = startAngle + driveDegrees;
		if(driveDegrees > 0){
			positiveDriveSpeed = abs(positiveDriveSpeed);
			while(gyr->GetAngle() <= targetAngle){
				double dPow = positiveDriveSpeed*((targetAngle-(gyr->GetAngle()))/driveDegrees);
				drov->ArcadeDrive(0.0, dPow, false);
			}
		}
		else{
			positiveDriveSpeed = -abs(positiveDriveSpeed);
			while(gyr->GetAngle() >= targetAngle){
				double dPow = positiveDriveSpeed*((targetAngle-(gyr->GetAngle()))/driveDegrees);
				drov->ArcadeDrive(0.0, dPow, false);
			}
		}
	}
}*/

void DriveSystem::GearVisionDrive(double stopDist){

}

