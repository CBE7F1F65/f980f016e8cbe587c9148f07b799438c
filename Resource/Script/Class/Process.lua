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

function Process:new(t)
    local t = t or {};
    self.__index = self;
    setmetatable( t, self );
    return t;
end

function Process:SnapShot(self)
	hge.System_Snapshot();
end

mp = Process:new();