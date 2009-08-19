Process	=	{
						keyUp		= RESCONFIGDEFAULT_KEYUP;
						keyDown		= RESCONFIGDEFAULT_KEYDOWN;
						keyLeft		= RESCONFIGDEFAULT_KEYLEFT;
						keyRight	= RESCONFIGDEFAULT_KEYRIGHT;
						
						keyPause	= RESCONFIGDEFAULT_KEYPAUSE;
						keySkip		= RESCONFIGDEFAULT_KEYSKIP;
						keyEnter	= RESCONFIGDEFAULT_KEYENTER;
						keyEscape	= RESCONFIGDEFAULT_KEYESCAPE;
						keyCapture	= RESCONFIGDEFAULT_KEYCAPTURE;
					}

function Process:NewProcess()
	local _process = Process;
	return _process;
end

function Process:SnapShot()
	hge.System_Snapshot();
end

mp = Process:NewProcess();