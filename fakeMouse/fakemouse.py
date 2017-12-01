import pyautogui
import serial

ser = serial.Serial(port='/dev/ttyACM0', baudrate=115200, timeout=.01, bytesize=8, parity='N', stopbits=1)
#print(ser)

pyautogui.FAILSAFE = False
pyautogui.PAUSE = 0

pos = True
neg = False


moveVars = {'x_dir':False, 
	'x_go':False, 
	'y_dir':False,
	'y_go':False, 
	'left_click':False, 
	'right_click':False}
	
def action(mvList, mv_data):
	if mv_data == b'\x00': mvList['left_click'] = False
	if mv_data == b'\x01': mvList['left_click'] = True
	if mv_data == b'\x02': mvList['right_click'] = True
	if mv_data == b'\x03': mvList['right_click'] = False
	
	if mv_data == b'\x04': mvList['y_dir'], mvList['y_go'] = neg, True
	if mv_data == b'\x06': mvList['y_dir'], mvList['y_go'] = pos, True
	if mv_data == b'\x05' or mv_data == b'\x07': mvList['y_go'] = False
	
	if mv_data == b'\x08': mvList['x_dir'], mvList['x_go'] = neg, True
	if mv_data == b'\n': mvList['x_dir'], mvList['x_go'] = pos, True
	if mv_data == b'\t' or mv_data == b'\x0b': mvList['x_go'] = False
	
	return mvList

def boolToDir(dirBool):
	if dirBool == True:
		return 2
	else:
		return -2

def doMove(mvList):
	if (mvList['x_go'] == True) and (mvList['y_go'] == True):
		pyautogui.moveRel(boolToDir(mvList['x_dir']), 
		boolToDir(mvList['y_dir']),
		0)
	elif mvList['x_go'] == True:
		pyautogui.moveRel(boolToDir(mvList['x_dir']), 
		0,
		0)
	elif mvList['y_go'] == True:
		pyautogui.moveRel(0, 
		boolToDir(mvList['y_dir']),
		0)
	else:
		pass
		
	if mvList['left_click'] == True:
		pyautogui.mouseDown(button='left')
	if mvList['left_click'] == False:
		pyautogui.mouseUp(button='left')
		
	if mvList['right_click'] == True:
		pyautogui.mouseDown(button='right')
	if mvList['right_click'] == False:
		pyautogui.mouseUp(button='right')
	
	
while True:
	a = ser.readline(1)
	#print(a)
	moveVars = action(moveVars,a)
	#print(moveVars)
	doMove(moveVars)
