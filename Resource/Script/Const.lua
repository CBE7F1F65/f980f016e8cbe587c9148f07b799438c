hgeConst	=	{
							HGE_WINDOWED		= 0x0101;    -- bool		run in window?		(default: false)
							HGE_ZBUFFER			= 0x0102;    -- bool		use z-buffer?		(default: false)
							HGE_TEXTUREFILTER	= 0x0103;    -- bool		texture filtering?	(default: true)
							
							HGE_USESOUND		= 0x0104;    -- bool		use BASS for sound?	(default: true)
							
							HGE_DONTSUSPEND		= 0x0105;	-- bool		focus lost:suspend?	(default: false)
							HGE_HIDEMOUSE		= 0x0106;	-- bool		hide system cursor?	(default: true)
							
							HGE_SHOWSPLASH		= 0x0107;	-- bool		hide system cursor?	(default: true)
							
							HGE_HWND			= 0x0301;	-- int		window handle: read only
							HGE_HWNDPARENT		= 0x0302;	-- int		parent win handle	(default: 0)
							HGE_SCREENWIDTH		= 0x0401;   -- int		screen width		(default: 800)
							HGE_SCREENHEIGHT	= 0x0402;   -- int		screen height		(default: 600)
							HGE_SCREENBPP		= 0x0403;   -- int		screen bitdepth		(default: 32) (desktop bpp in windowed mode)
							
							HGE_SAMPLERATE		= 0x0404;   -- int		sample rate			(default: 44100)
							HGE_SAMPLEVOLUME	= 0x0405;	-- int		global sample volume(default: 10000)
							HGE_FXVOLUME		= 0x0406;   -- int		global fx volume	(default: 10000)
							HGE_STREAMVOLUME	= 0x0407;   -- int		global music volume	(default: 10000)	
							HGE_FPS				= 0x0408;	-- int		fixed fps			(default: HGEFPS_UNLIMITED)
						
							HGE_FRAMECOUNTER	= 0x0409;	--int		frame counter;	read only
							HGE_FRAMESKIP		= 0x040A;	--int		frame skip			(default: 0)
							HGE_RENDERSKIP		= 0x040B;	--int		render skip			(default: 0)
							
							HGE_ICON			= 0x0501;   -- char*	icon resource		(default: NULL)
							HGE_TITLE			= 0x0502;   -- char*	window title		(default: "HGE")
							
							HGE_INIFILE			= 0x0503;   -- char*	ini file			(default: NULL) (meaning no file)
							HGE_LOGFILE			= 0x0504;   -- char*	log file			(default: NULL) (meaning no file)
						
							HGE_BASSDLLFILE		= 0x0505;	-- char*	bass.dll file		(default: "BASS.dll")
						}