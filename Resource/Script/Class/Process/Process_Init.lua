function Process:ProcessInit()
	time = time + 1
	if time == 1 then
		return self:ProcessPreInitial();
	end
	
	if self.texInit ~= NULL then
		hge.Texture_Free(self.texInit);
		self.texInit = NULL;
	end
	
	data:Init(hge.Ini_GetString(RESCONFIGS_RESOURCE, RESCONFIGN_RESOURCEFILE, RESCONFIGDEFAULT_RESOURCEFILE));
	tex:Init(RESDEFAULT_DATAFOLDER..RESDEFAULT_TEXTUREDEFINE);
	spim:Init(RESDEFAULT_DATAFOLDER..RESDEFAULT_SPRITEITEMDEFINE);
	effm:Init(RESDEFAULT_DATAFOLDER..RESDEFAULT_EFFECTDEFINE);
	se:Init(RESDEFAULT_DATAFOLDER..RESDEFAULT_SEDEFINE);
	music:Init(RESDEFAULT_DATAFOLDER..RESDEFAULT_MUSICDEFINE);


	font = hgeFont.NewFont("Graphic/Font/font.fnt");
	eff = effm:NewES(EFF_HOSHI);
	hgeES.Fire(eff);
	for i=1,MAXEFF do
		effs[i] = hgeES.NewES(eff);
		hgeES.Fire(effs[i]);
	end
	
	spball = spim:NewSprite(SI_BALL);
	spitem = spim:NewSprite(SI_BATTLE_1);
	music:MusicChange(MUS_01);
	
	time = 0;
	self.state = STATE_TITLE;
	return PTURN;
end