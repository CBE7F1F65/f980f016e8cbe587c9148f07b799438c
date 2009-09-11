function Process:ProcessTitle()
	
	time = time + 1;
	if time == 1 then
		spim.sprites.sptitle = spim:NewSprite(SI_TITLE);
		spim.sprites.titles = {};
		spim.sprites.titles.sptitle = spim:NewSprite(SI_TITLE);
		
		sel:PushSelector(SI_GAMESTART, M_CLIENT_CENTER_X, M_CLIENT_CENTER_Y + 48, 1.5);
		sel:PushSelector(SI_REPLAY, M_CLIENT_CENTER_X, M_CLIENT_CENTER_Y + 120, 1.5);
		sel:PushSelector(SI_EXIT, M_CLIENT_CENTER_X, M_CLIENT_CENTER_Y + 192, 1.5);
		sel:NewSelection(1, SELSAVE_TITLE);
		
		music:MusicChange(MUS_01);
	end
	
	local selret = sel:Action();
	if selret > 0 and sel.saved[SELSAVE_DIFFICULT] == nil then
		sel:PushSelector(SI_EASY, M_CLIENT_CENTER_X, M_CLIENT_CENTER_Y + 48, 1.5);
		sel:PushSelector(SI_NORMAL, M_CLIENT_CENTER_X, M_CLIENT_CENTER_Y + 88, 1.5);
		sel:PushSelector(SI_HARD, M_CLIENT_CENTER_X, M_CLIENT_CENTER_Y + 128, 1.5);
		sel:PushSelector(SI_h5nc, M_CLIENT_CENTER_X, M_CLIENT_CENTER_Y + 168, 1.5);
		sel:NewSelection(1, SELSAVE_DIFFICULT);
	end
	
	if sel.saved[SELSAVE_DIFFICULT] ~= nil then
		time = 0;
		self.state = STATE_START;
		return PTURN;
	end
	
	return PGO;
end