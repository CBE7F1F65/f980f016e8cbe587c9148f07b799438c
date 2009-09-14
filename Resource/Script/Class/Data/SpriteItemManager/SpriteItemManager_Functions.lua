function SpriteItemManager:NewSprite(siindex)
	return hgeSprite.NewSprite(self.tex[siindex], self.texx[siindex], self.texy[siindex], self.texw[siindex], self.texh[siindex]);
end

function SpriteItemManager:Init(tablefilename)
	if tablefilename == nil or tablefilename == "" then
		return;
	end
	local tabledata = {};
	local linecount;
	
	tabledata, linecount = tablefile:GetTableFileData(tablefilename, "nssffff");
	local siindex;
	local texw;
	local texh;
	local oritexw;
	local oritexh;
	for i=1, linecount do
		siindex = tabledata[1][i];
		luastate.SetConst(tabledata[2][i], siindex);
		self.tex[siindex] = luastate.GetConst(tabledata[3][i]);
		self.texx[siindex] = tabledata[4][i];
		self.texy[siindex] = tabledata[5][i];
		texw = tabledata[6][i];
		texh = tabledata[7][i];
		if texw < 0 or texh < 0 then
			oritexw, oritexh = hge.Texture_GetWH(self.tex[siindex]);
			if texw < 0 then
				texw = oritexw;
			end
			if texh < 0 then
				texh = oritexh;
			end
		end
		self.texw[siindex] = texw;
		self.texh[siindex] = texh;
	end
end

function SpriteItemManager:Push(layer, _able, spriteindex, _x, _y, _rot, _hscale, _vscale, color)
	local spriteitem = 
		{
			sprite = self:NewSprite(spriteindex);
			able = _able;
			x = _x;
			y = _y;
			rot = _rot;
			hscale = _hscale;
			vscale = _vscale;
			color = _color;
		}
	if self.renderlist[layer] == nil then
		self.renderlist[layer] = {};
	end
	local tindex = table.getn(self.renderlist[layer]) + 1;
	self.renderlist[layer][tindex] = spriteitem;
	return spriteitem;
end

function SpriteItemManager:ClearItems(items)
	for i, it in pairs(self.renderlist) do
		for j, jt in pairs(it) do
			for k, kt in pairs(items) do
				if kt == jt then
					hgeSprite.DeleteSprite(jt.sprite);
					break;
				end
			end
			jt = nil;
		end
	end
end

function SpriteItemManager:Clear()
	for i, it in pairs(self.renderlist) do
		for j, jt in pairs(it) do
--			hgeSprite.DeleteSprite(jt.sprite);
--			jt = nil;
		end
	end
end

function SpriteItemManager:RenderSprites()
	for i, it in pairs(self.renderlist) do
		for j, jt in pairs(it) do
			if jt.color ~= nil then
				hgeSprite.SetColor(jt.sprite, jt.color);
			end
			if jt.able then
				hgeSprite.RenderEx(jt.sprite, jt.x, jt.y, jt.rot, jt.hscale, jt.vscale);
			end
		end
	end
end