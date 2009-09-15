Process	=	{
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
	self.keyA				=	RESCONFIGDEFAULT_KEYA;
	self.keyS				=	RESCONFIGDEFAULT_KEYS;
	self.keyD				=	RESCONFIGDEFAULT_KEYD;
	self.keyZ				=	RESCONFIGDEFAULT_KEYZ;
	self.keyX				=	RESCONFIGDEFAULT_KEYX
	self.keyC				=	RESCONFIGDEFAULT_KEYC;
	self.keySpace		=	RESCONFIGDEFAULT_KEYSpace;
	self.keyPause		= RESCONFIGDEFAULT_KEYPAUSE;
	self.keySkip		= RESCONFIGDEFAULT_KEYSKIP;
	self.keyEnter		= RESCONFIGDEFAULT_KEYENTER;
	self.keyCancel	=	RESCONFIGDEFAULT_KEYCANCEL;
	self.keyEscape	= RESCONFIGDEFAULT_KEYESCAPE;
	self.keyCapture	= RESCONFIGDEFAULT_KEYCAPTURE;
	
	self.joyA				=	RESCONFIGDEFAULT_JOYA;
	self.joyS				=	RESCONFIGDEFAULT_JOYS;
	self.joyD				=	RESCONFIGDEFAULT_JOYD;
	self.joyZ				=	RESCONFIGDEFAULT_JOYZ;
	self.joyX				=	RESCONFIGDEFAULT_JOYX
	self.joyC				=	RESCONFIGDEFAULT_JOYC;
	self.joySpace		=	RESCONFIGDEFAULT_JOYSpace;
	self.joyPause		=	RESCONFIGDEFAULT_JOYPAUSE;
	self.joyEnter		=	RESCONFIGDEFAULT_JOYENTER;
	self.joyCancel	=	RESCONFIGDEFAULT_JOYCANCEL;
	
	self.state	=	STATE_INIT;
	
	self.texInit	=	NULL;
	
	self.worldx	=	0;
	self.worldy	=	0;
	self.worldz	=	0;
	
end

function Process:Release()
	
	hge.Ini_SetInt(RESCONFIGS_KEYSETTING, RESCONFIGN_KEYUP, self.keyUp);
	hge.Ini_SetInt(RESCONFIGS_KEYSETTING, RESCONFIGN_KEYDOWN, self.keyDown);
	hge.Ini_SetInt(RESCONFIGS_KEYSETTING, RESCONFIGN_KEYLEFT, self.keyLeft);
	hge.Ini_SetInt(RESCONFIGS_KEYSETTING, RESCONFIGN_KEYRIGHT, self.keyRight);
	hge.Ini_SetInt(RESCONFIGS_KEYSETTING, RESCONFIGN_KEYPAUSE, self.keyPause);
	hge.Ini_SetInt(RESCONFIGS_KEYSETTING, RESCONFIGN_KEYSKIP, self.keySkip);
	hge.Ini_SetInt(RESCONFIGS_KEYSETTING, RESCONFIGN_KEYENTER, self.keyEnter);
	hge.Ini_SetInt(RESCONFIGS_KEYSETTING, RESCONFIGN_KEYCANCEL, self.keyCancel);
	hge.Ini_SetInt(RESCONFIGS_KEYSETTING, RESCONFIGN_KEYESCAPE, self.keyEscape);
	hge.Ini_SetInt(RESCONFIGS_KEYSETTING, RESCONFIGN_KEYCAPTURE, self.keyCapture);

	hge.Ini_SetInt(RESCONFIGS_JOYSETTING, RESCONFIGN_JOYPAUSE, self.joyPause);
	if __DEBUG > 0 then
		hge.Ini_SetInt(RESCONFIGS_JOYSETTING, RESCONFIGN_DEBUG_JOYSPEEDUP, self.debug_joySpeedUp);
	end

	hge.Ini_SetInt(RESCONFIGS_VOLUME, RESCONFIGN_VOLMUSIC, self.bgmvol);
	hge.Ini_SetInt(RESCONFIGS_VOLUME, RESCONFIGN_VOLSE, self.sevol);

	hge.Ini_SetInt(RESCONFIGS_CUSTOM, RESCONFIGN_SCREENMODE, self.screenmode);
	hge.Ini_SetInt(RESCONFIGS_CUSTOM, RESCONFIGN_DIFFICULT, self.nowdifflv);
	hge.Ini_SetString(RESCONFIGS_CUSTOM, RESCONFIGN_USERNAME, self.username);
	
	if self.texInit ~= NULL then
		hge.Texture_Free(self.texInit);
	end
	
	tex:Release();
	se:Release();
	spim:Release();
	effm:Release();
	music:Release();
	
	self:_Init();
	
end

mp = Process:new();