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
	
	time = 0;
	self.state = STATE_TITLE;
	return PTURN;
end