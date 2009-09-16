function Process:ProcessTitle()
	
	time = time + 1;
	if time == 1 then
		spim:Clear();
		sel:ClearSaved();
		spim.sprites.titles = {};
		spim.sprites.titles.sptitle = spim:Push(true, SI_TITLE,
			M_CLIENT_CENTER_X, M_CLIENT_CENTER_Y - 96,
			0, 2.5);
		
		data.dt.rpyloaded = false;
		data.dt.replaying = false;
		self:_PushSelection(SELSAVE_TITLE);
		
		music:MusicChange(MUS_01);
	end
	
	if data.dt.rpyloaded then
		local filename, content, length = global.ReceiveOpenFileName(export:GetPassword());
		local failed = false;
		if filename == "" or length <= 0 or luastate.DWORDToInt(content) == NULL then
			failed = true;
		else
			MB(global.ReadMemory(content, 0));
			hge.Resource_Free(content);
		end
		if failed then
			return PTITLE;
		end
		data.dt.replaying = true;
		sel.saved[SELSAVE_DIFFICULT] = 4;
		time = 0;
		self.state = STATE_START;
		return PTURN;
	end
	
	if hge.Input_GetDIKey(self.keyCancel, DIKEY_DOWN) then
		se:Push(SE_SYSTEM_CANCEL);
		if not sel:IsSaved(SELSAVE_TITLE) then
			if sel.nowindex == 3 then
				return PQUIT;
			end
			sel:MoveToSelection(3, false);
		else
			sel:CloseSelection();
			self:_PushSelection(SELSAVE_TITLE, sel.saved[SELSAVE_TITLE]);
			sel:ClearSaved(SELSAVE_TITLE);
		end
	end
	
	local selret = sel:Action();
	if not sel:IsSaved(SELSAVE_DIFFICULT) then
		if selret == 1 then
			self:_PushSelection(SELSAVE_DIFFICULT, self.nowdifflv);
		elseif selret == 2 then
			global.SetOpenFileName("Replay File (*.rpy)|*.rpy", "rpy", "Load Replay");
			data.dt.rpyloaded = true;
		end
	end
	
	if sel:IsSaved(SELSAVE_DIFFICULT) then
		time = 0;
		self.state = STATE_START;
		return PTURN;
	end
	
	return PGO;
end

function Process:_PushSelection(selsave, defaultsel)
	if defaultsel == nil then
		defaultsel = 1;
	end
	if selsave == SELSAVE_TITLE then
		sel:PushSelector(SI_GAMESTART, M_CLIENT_CENTER_X, M_CLIENT_CENTER_Y + 48, 1.5);
		sel:PushSelector(SI_REPLAY, M_CLIENT_CENTER_X, M_CLIENT_CENTER_Y + 120, 1.5);
		sel:PushSelector(SI_EXIT, M_CLIENT_CENTER_X, M_CLIENT_CENTER_Y + 192, 1.5);
		sel:NewSelection(defaultsel, selsave);
	elseif selsave == SELSAVE_DIFFICULT then
		sel:PushSelector(SI_EASY, M_CLIENT_CENTER_X, M_CLIENT_CENTER_Y + 48, 1.5);
		sel:PushSelector(SI_NORMAL, M_CLIENT_CENTER_X, M_CLIENT_CENTER_Y + 88, 1.5);
		sel:PushSelector(SI_HARD, M_CLIENT_CENTER_X, M_CLIENT_CENTER_Y + 128, 1.5);
		sel:PushSelector(SI_h5nc, M_CLIENT_CENTER_X, M_CLIENT_CENTER_Y + 168, 1.5);
		sel:NewSelection(defaultsel, selsave);
	elseif selsave == SELSAVE_PAUSE then
		sel:PushSelector(SI_RESUME, M_CLIENT_CENTER_X, M_CLIENT_CENTER_Y, 1.5);
		sel:PushSelector(SI_RETRY, M_CLIENT_CENTER_X, M_CLIENT_CENTER_Y + 48, 1.5);
		sel:PushSelector(SI_BACKTOTITLE, M_CLIENT_CENTER_X, M_CLIENT_CENTER_Y + 96, 1.5);
		sel:NewSelection(defaultsel, selsave);
	elseif selsave == SELSAVE_OVER then
		sel:PushSelector(SI_SAVEREPLAY, M_CLIENT_CENTER_X, M_CLIENT_CENTER_Y, 1.5);
		sel:PushSelector(SI_RETRY, M_CLIENT_CENTER_X, M_CLIENT_CENTER_Y + 48, 1.5);
		sel:PushSelector(SI_BACKTOTITLE, M_CLIENT_CENTER_X , M_CLIENT_CENTER_Y + 96, 1.5);
		sel:NewSelection(defaultsel, selsave);
	elseif selsave == SELSAVE_CONFIRM then
		sel:PushSelector(SI_YES, M_CLIENT_CENTER_X, M_CLIENT_CENTER_Y + 48, 1.5);
		sel:PushSelector(SI_NO, M_CLIENT_CENTER_X, M_CLIENT_CENTER_Y + 96, 1.5);
		sel:NewSelection(defaultsel, selsave);
	end
end

function Process:_RenderTitle()
	spim:RenderItem(spim.sprites.titles.sptitle);
	sel:Render();
end