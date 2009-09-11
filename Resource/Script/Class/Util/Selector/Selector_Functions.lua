function Selector:PushSelector(spriteid, x, y, scalefactor)
	local tindex = table.getn(self.selinfo) + 1;
	self.selinfo[tindex] = {};
	self.selinfo[tindex].sprite = spim:NewSprite(spriteid);
	self.selinfo[tindex].x = x;
	self.selinfo[tindex].y = y;
	self.selinfo[tindex].scale = 1.0;
	if scalefactor == nil then
		scalefactor = 1.0;
	end
	self.selinfo[tindex].scalefactor = scalefactor;
	self.alpha = 0;
end

function Selector:NewSelection(defaultindex, saveas)
	self.selnum = table.getn(self.selinfo);
	if defaultindex == nil or defaultindex < 1 or defaultindex > self.selnum then
		defaultindex = 1;
	end
	self.nowindex = defaultindex;
	self.saveas = saveas;
	self.able = true;
	self.timer = 0;
	self.exiting = false;
end

function Selector:_DeleteSelection()
	if self.saveas ~= nil and self.saveas >= 1 then
		self.saved[self.saveas] = self.nowindex;
	end
	self.able = false;
	self.selinfo = {};
	return self.nowindex;
end

function Selector:Action()
	self.timer = self.timer + 1;
	if self.timer <= M_FADETIME then
		self.alpha = 0xff * self.timer / M_FADETIME;
	end
	if self.exiting then
		if self.timer >= M_FADETIME then
			return self:_DeleteSelection();
		end
		self.alpha = 0xff - self.alpha;
		return 0;
	end
	
	if hge.Input_GetDIKey(mp.keyDown, DIKEY_DOWN) then
		self.nowindex = self.nowindex + 1;
		if self.nowindex > self.selnum then
			self.nowindex = 1;
		end
	elseif hge.Input_GetDIKey(mp.keyUp, DIKEY_DOWN) then
		self.nowindex = self.nowindex - 1;
		if self.nowindex <= 0 then
			self.nowindex = self.selnum;
		end
	end
	
	if hge.Input_GetDIKey(mp.keyEnter, DIKEY_DOWN) then
		self.exiting = true;
		self.timer = 0;
	end
	
	local tscale = global.ROLL(self.timer, M_FADETIME) / M_FADETIME / 4 + 1.0;
	for i, it in pairs(self.selinfo) do
		if self.nowindex == i then
			it.scale = tscale;
		else
			it.scale = 1.0;
		end
	end
	return 0;
end

function Selector:Render()
	if not self.able then
		return;
	end
	for i, it in pairs(self.selinfo) do
		hgeSprite.SetColor(it.sprite, global.ARGB(self.alpha, 0xffffff));
		hgeSprite.RenderEx(it.sprite, it.x, it.y, 0, it.scale * it.scalefactor);
	end
end