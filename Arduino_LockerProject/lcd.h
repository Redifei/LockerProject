#ifndef LCD_H
#define LCD_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "locker.h"
#include "key.h"
#include "lockDevice.h"
#include "config.h"

class LcdClass
{
public:
	// ������
	LcdClass(); 
	LcdClass(LiquidCrystal_I2C* const liquidCrystalPtr);

	void	begin(LockerClass* const myLocker, KeypadClass* const myKeypad); // �ʱ� ����
	void	writeLcd();					// LCD ���
	void	writeErrLcd(int errCnt);	// LCD ���� �޽��� ���
	
private:
	enum {
		INITAL_LCD = 0, SELECT_LCD = 2, PASSWORD_LCD = 3,
		OPEN_LCD = 4, CLOSE_LCD = 6, ERROR_LCD = 8
	};

	void	initalLcd();				// 1. �ʱ� ���� LCD
	void	selectLcd();				// 2. ���� ���� LCD
	void	passwordLcd();				// 3. ��й�ȣ �Է� ���� LCD
	void	openLcd();					// 4. ��Ŀ ���� ���� ���� LCD
	void	closeLcd();					// 5. ��Ŀ ���� ���� ���� LCD
	void	adminLcd();					// ������ ���� LCD

	void	errorLcd(int errCnt);		// ���� LCD

	void	setWasErrorState(boolean err) { wasErrorState = err; }
	boolean getWasErrorState() { return wasErrorState; }

	LiquidCrystal_I2C*	_myLcd;			// LiquidCrystal_I2C(���̺귯��) Ŭ���� ������
	LockerClass*		_myLocker;		// ��Ŀ Ŭ���� ������
	KeypadClass*		_myKeypad;			// Ű�е� Ŭ���� ������
	
	static String		lcdMsg[];		// ��� ���ڿ�
	static String		lcdKeyword[];	// ��� Ű����

	boolean				wasErrorState;	// ���� ���°� �������� ����
};

#endif
