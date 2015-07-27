#ifndef LOCKDEVICE_H
#define LOCKDEVICE_H

#include <Arduino.h>
#include "config.h"

class LockDeviceClass
{
public:
	LockDeviceClass(const int* const lockPtr, const int* const limSwPtr); // ������

	void	lockOn(int lockerNum);			// ��Ŀ ��� ����
	void	lockOff(int lockerNum);			// ��Ŀ ��� ����

	boolean isLimSwOn(int lockerNum);		// ��Ŀ ���� �������� ����
	int		getLimSwOnTime(int lockerNum);	// ��Ŀ ���� ����ä ������ �ð�

private:
	void	lockInit();						// �����ġ(�ַ����̵�) �ʱ�ȭ
	void	limSwInit();					// ����Ʈ ����ġ �ʱ�ȭ

	const int* const _lockPtr;				// �����ġ(�ַ����̵�)�� ������
	const int* const _limSwPtr;				// ����Ʈ ����ġ �� ������
};

#endif