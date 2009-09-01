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