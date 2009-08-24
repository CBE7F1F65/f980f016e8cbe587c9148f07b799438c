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
    setmetatable(t, self);
    t:_Init();
    return t;
end

function Process:_Init()
	
	self.keyUp			= RESCONFIGDEFAULT_KEYUP;
	self.keyDown		= RESCONFIGDEFAULT_KEYDOWN;
	self.keyLeft		= RESCONFIGDEFAULT_KEYLEFT;
	self.keyRight		= RESCONFIGDEFAULT_KEYRIGHT;
	self.keyPause		= RESCONFIGDEFAULT_KEYPAUSE;
	self.keySkip		= RESCONFIGDEFAULT_KEYSKIP;
	self.keyEnter		= RESCONFIGDEFAULT_KEYENTER;
	self.keyEscape	= RESCONFIGDEFAULT_KEYESCAPE;
	self.keyCapture	= RESCONFIGDEFAULT_KEYCAPTURE;
	
	self.joyPause		=	RESCONFIGDEFAULT_JOYPAUSE;
	
	self.state	=	STATE_INIT;
	
end

function Process:SnapShot()
	hge.System_Snapshot();
end

mp = Process:new();